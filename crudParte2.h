#ifndef CRUDPARTE2_H_INCLUDED
#define CRUDPARTE2_H_INCLUDED
//struct categoria;

int indexCategoria = 0;
int categoriaValidas = 0;

struct categoria {
    int categoria_id;
    char nomeCategoria[20];
};

int indiceCategoria (){  //Retorna o valor do indice

    int x = 0;
    char aux[100];
    FILE *arq = fopen("dataCategoria.txt", "r+");
        if(arq == NULL){
            return x;
        } else {
            while( !feof ( arq ) ) {
                fscanf(arq, "%[^\n]\n", aux);   // Passa pelo arquivo
                x++;
            }
        }
    fclose(arq);
    indexCategoria = x;
    return x;
}

categoria create_categoria(int id = -1){

    categoria aux;
    if(id >= 0){
        aux.categoria_id = id;
    } else{
        aux.categoria_id = indiceCategoria();
    }

    cout<< "\tID da categoria: " << aux.categoria_id << endl;

    //fflush(stdin);
    cout<< "Nome da categoria: ";
    gets(aux.nomeCategoria);
    cout << endl;

    return aux;

}

void updateCategoria(categoria aux){

    //data aux = create();
    FILE *arq = fopen("dataCategoria.txt", "a+");
    if (arq == NULL) {
        cout<<"\n\tErro na Leitura/Gravacao do arquivo!";
    }else{
        fprintf(arq, "%i\t%s\n",aux.categoria_id, aux.nomeCategoria);
    }
    fclose(arq);
}

void Imprimir_pesquisaCategoria(categoria toShow){

    printf("\n\nProduct_id: %i\n Nome: %s \n\n",toShow.categoria_id, toShow.nomeCategoria);

}

void listar_categorias(categoria * toShow){
    for (int i = 0; i > indexCategoria; i++){
        printf("%i - %s", toShow[i].categoria_id, toShow[i].nomeCategoria);
    }
}

categoria *openFileCategorias(int n){
    categoriaValidas = 0;
    categoria * toLoad = (categoria *)calloc(n, sizeof(categoria));
    if(toLoad == NULL){
        cout << "n�o h� memoria suficiente";
    } else {
        FILE *arq = fopen("dataCategoria.txt", "r+");
        int i = 0;
        if(arq){
            while( !feof(arq) ){
                fscanf( arq, "%i\t%[^\n]\n", toLoad[i].categoria_id, toLoad[i].nomeCategoria);
                if(!(toLoad[i].categoria_id <= -1)){//id negativo serve como lapide
                    categoriaValidas++;
                    i++;
                }else{
                    Imprimir_pesquisaCategoria(toLoad[i]);
                }
            }
        }
        fclose(arq);
    }
    return toLoad;
}

categoria *alteraFileCategorias(int n, int id, bool opcExclusao = false){
    categoriaValidas = 0;
    bool finded = false;
    categoria * toLoad = (categoria *)calloc(n, sizeof(categoria));

    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("dataCategoria.txt", "r+");
        int i = 0;
        if(arq){
            while( !feof(arq) ){
                fscanf( arq, "%i\t%[^\n]\n", toLoad[i].categoria_id, toLoad[i].nomeCategoria);
                if(!(toLoad[i].categoria_id <= -1)){//id negativo serve como lapide
                    if(toLoad[i].categoria_id == id){
                        //anda no arquivo
                        finded = true;
                        cout << "Produto pra ser alterado:\n";
                        Imprimir_pesquisaCategoria(toLoad[i]);
                        if(!opcExclusao){
                            toLoad[i] = create_categoria(id);
                            toLoad[i].categoria_id = id;
                        }
                        if(opcExclusao){
                            toLoad[i].categoria_id = -2;
                        }
                    }
                    categoriaValidas++;
                    i++;
                } else {
                    i++;
                }
            }
        }
        fclose(arq);
        FILE *arqNovo = fopen("dataCategoria.txt", "w+");
        int a = 0;
        while(a < i){
            fprintf(arqNovo, "%i\t%s\t%s\t%f\t%i\t%s\n",
                        toLoad[a].categoria_id, toLoad[a].nomeCategoria);
                a++;
            }
            fclose(arqNovo);
        }

        if(!finded){
            cout<<"Categoria não encontrada.\n\n";
        }
        return toLoad;
}

#endif // CELULA_H_INCLUDED
