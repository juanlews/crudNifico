#ifndef CRUDPRODUTO_INCLUDED
#define CRUDPRODUTO_INCLUDED

int indexProduto = 0, validosProduto = 0; //

struct produto{//

    int product_id;
    char name[20];
    char description[25];
    float price;
    int quantity;
    char source[15];

};

int indiceProduto (){  //Retorna o valor do indice//

    int x = 0;
    char aux[100];
    FILE *arq = fopen("dataProduto.txt", "r+");
        if(arq == NULL){
            return x;
        } else {
            while( !feof ( arq ) ) {
                fscanf(arq, "%[^\n]\n", aux);   // Passa pelo arquivo
                x++;
            }
        }
    fclose(arq);
    indexProduto = x;
    return x;
}

produto createProduto(int id = -1){//

    produto aux;
    if(id >= 0){
        aux.product_id = id;
    } else{
        aux.product_id = indiceProduto();
    }

    cout<< "\tID do Produto: " << aux.product_id << endl;

    //fflush(stdin);
    cout<< "Nome do produto: ";
    gets(aux.name);

    cout<< "Descricao do produto: ";
    gets(aux.description);

    cout<< "Preco do produto: ";
    scanf("%f", &aux.price);

    cout<< "Quantidade do produto: ";
    cin>> aux.quantity;

    cin.ignore();
    cout<< "Origem do produto: ";
    gets(aux.source);
    cout << endl;

return aux;
}

void updateProduto(produto aux){//

    //produto aux = create();
    FILE *arq = fopen("dataProduto.txt", "a+");
    if (arq == NULL) {
        cout<<"\n\tErro na Leitura/Gravacao do arquivo!";
    }else{
        fprintf(arq, "%i\t%s\t%s\t%f\t%i\t%s\n",aux.product_id, aux.name, aux.description, aux.price, aux.quantity, aux.source);
    }
    fclose(arq);
}

void Imprimir_pesquisaProduto(produto toShow){//

    printf("\n\tProduct_id: %i\n Nome: %s\n Descricao: %s\n Preco: %f\n Quantidade: %i\n Origem: %s\n\n",
            toShow.product_id, toShow.name, toShow.description, toShow.price, toShow.quantity, toShow.source);

}

produto *openFileProduto(int n){//
    validosProduto = 0;
    produto * toLoad = (produto *)calloc(n, sizeof(produto));
    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("dataProduto.txt", "r+");
        int i = 0;
        if(arq){
            while( !feof(arq) ){
                fscanf
                    ( arq, "%i\t%[^\t]\t%[^\t]\t%f\t%i\t%[^\n]\n",
                     &toLoad[i].product_id, &toLoad[i].name, &toLoad[i].description, &toLoad[i].price,&toLoad[i].quantity, &toLoad[i].source);
                if(!(toLoad[i].product_id <= -1)){//id negativo serve como lapide
                    validosProduto++;
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

produto *alteraFileProduto(int n, int id, bool opcExclusao = false){//
    validosProduto = 0;
    bool finded = false;
    produto * toLoad = (produto *)calloc(n, sizeof(produto));

    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("dataProduto.txt", "r+");
        int i = 0;
        if(arq){
            while( !feof(arq) ){
                fscanf
                    ( arq, "%i\t%[^\t]\t%[^\t]\t%f\t%i\t%[^\n]\n",
                     &toLoad[i].product_id, &toLoad[i].name, &toLoad[i].description, &toLoad[i].price,&toLoad[i].quantity, &toLoad[i].source);
                if(!(toLoad[i].product_id <= -1)){//id negativo serve como lapide
                        if(toLoad[i].product_id == id){
                            //anda no arquivo
                            finded = true;
                            cout << "Produto pra ser alterado:\n";
                            Imprimir_pesquisaProduto(toLoad[i]);
                            if(!opcExclusao){
                                toLoad[i] = createProduto(id);
                                toLoad[i].product_id = id;
                            }
                            if(opcExclusao){
                                toLoad[i].product_id = -2;
                            }
                        }
                    validosProduto++;
                    i++;
                }else{
                    i++;
                }
            }
        }
        fclose(arq);
        FILE *arqNovo = fopen("dataProduto.txt", "w+");
        int a = 0;
        while(a < i){
            fprintf(arqNovo, "%i\t%s\t%s\t%f\t%i\t%s\n",
                    toLoad[a].product_id, toLoad[a].name, toLoad[a].description, toLoad[a].price, toLoad[a].quantity, toLoad[a].source);
            a++;
        }
        fclose(arqNovo);
    }

    if(!finded){
        cout<<"Produto não encontrado.\n\n";
    }
    return toLoad;
}

#endif