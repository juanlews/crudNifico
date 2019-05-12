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

void create_categoria(int id = -1){

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

//return aux;

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
                    //Imprimir_pesquisa(toLoad[i]);
                }
            }
        }
        fclose(arq);
    }
    return toLoad;
}

#endif // CELULA_H_INCLUDED
