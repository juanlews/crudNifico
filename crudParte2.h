#ifndef CRUDPARTE2_H_INCLUDED
#define CRUDPARTE2_H_INCLUDED
//struct categoria;

int indexCategoria = 0;

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

#endif // CELULA_H_INCLUDED
