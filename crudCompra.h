#ifndef CRUDCOMPRA_H_INCLUDED
#define CRUDCOMPRA_H_INCLUDED

int indexCompra = 0, validosCompra = 0;

struct compra {
    int compra_id;
    int compra_cliente;
    char dataCompra[50];
    //float totalCompra;  //=  insercao de produtos comprados, cria arquivo e retorna total    -->ex: produtoComprado()
};

bool pesquisaCompra (compra *aux, int id){
    for (int i = 0; i < indexCompra; i++){
        if (aux[i].compra_id == id){
            return true;
        }
    }
    return false;
}

int indiceCompra (){  //Retorna o valor do indice

    int x = 0;
    char aux[100];
    FILE *arq = fopen("dataCompra.txt", "r+");
        if(arq == NULL){
            return x;
        } else {
            while( !feof ( arq ) ) {
                fscanf(arq, "%[^\n]\n", aux);   // Passa pelo arquivo
                x++;
            }
        }
    fclose(arq);
    indexCompra = x;
    return x;
}

compra create_compra(int id = -1){

    compra aux;
    if(id >= 0){
        aux.compra_id = id;
    } else{
        aux.compra_id = indiceCompra();
    }

    cout<< "\tID da compra: " << aux.compra_id << endl;

    cout<< "\tID cliente efetuando a compra: "<< idCliente << endl;
    aux.compra_cliente = idCliente;

    //aux.totalCompra = 0;//incluiCarrinho(); //adicionar produtos e retorna total

    fflush(stdin);
    cout<< "Data compra: ";
    gets(aux.dataCompra);
    cout << endl;

return aux;

}

void updateCompra(compra aux){

    FILE *arq = fopen("dataCompra.txt", "a+");
    if (arq == NULL) {
        cout<<"\n\tErro na Leitura/Gravacao do arquivo!";
    }else{
        fprintf(arq, "%i\t%i\t%s\n",aux.compra_id, aux.compra_cliente, aux.dataCompra);
    }
    fclose(arq);
}

void Imprimir_pesquisaCompra(compra toShow){

    printf("\n\tCompra ID: %i\n Cliente ID: %i\n Data compra: %s\n\n",
            toShow.compra_id, toShow.compra_cliente, toShow.dataCompra);

}

compra *openFileCompra(int n){
    validosCompra = 0;
    compra * toLoad = (compra *)calloc(n, sizeof(compra));
    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("dataCompra.txt", "r+");
        int i = 0;
        if(arq){
            while( !feof(arq) ){
                fscanf
                    ( arq, "%i\t%i\t%[^\n]\n",
                     &toLoad[i].compra_id, &toLoad[i].compra_cliente, &toLoad[i].dataCompra);
                if(!(toLoad[i].compra_id <= -1)){//id negativo serve como lapide
                    validosCompra++;
                    i++;
                }else{
                    //Imprimir_pesquisaCompra(toLoad[i]);
                }
            }
        }
        fclose(arq);
    }
    return toLoad;
}

compra *alteraFileCompra(int n, int id, cliente *clientes, bool opcExclusao = false){
    validosCompra = 0;
    bool finded = false, cond = false;
    compra * toLoad = (compra *)calloc(n, sizeof(compra));

    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("dataCompra.txt", "r+");
        int i = 0;
        if(arq){
            while( !feof(arq) ){
                fscanf
                    ( arq, "%i\t%i\t%[^\n]\n",
                     &toLoad[i].compra_id, &toLoad[i].compra_cliente, &toLoad[i].dataCompra);
                if(!(toLoad[i].compra_id <= -1)){//id negativo serve como lapide
                        if(toLoad[i].compra_id == id){
                            //anda no arquivo
                            finded = true;
                            cout << "Produto pra ser alterado:\n";
                            Imprimir_pesquisaCompra(toLoad[i]);
                            if(!opcExclusao){
                            cout<< "Qual o id do cliente que efetuara compra: ";
                                do{
                                    cin>> idCliente;
                                    if (pesquisaCliente(clientes, idCliente)){
                                        toLoad[i] = create_compra(id);
                                        toLoad[i].compra_id = id;
                                        cond = true;
                                    } else {
                                        cout<< "ID de categoria nao encontrado, tente outro: ";
                                    }
                                } while (!cond);
                            }
                            if(opcExclusao){
                                toLoad[i].compra_id = -2;
                            }
                        }
                    validosCompra++;
                    i++;
                }else{
                    i++;
                }
            }
        }
        fclose(arq);
        FILE *arqNovo = fopen("dataCompra.txt", "w+");
        int a = 0;
        while(a < i){
            fprintf(arqNovo, "%i\t%i\t%s\n",
                    toLoad[a].compra_id, toLoad[a].compra_cliente, toLoad[a].dataCompra);
            a++;
        }
        fclose(arqNovo);
    }

    if(!finded){
        cout<<"Produto não encontrado.\n\n";
    }
    return toLoad;
}

compra PesquisarCompra(compra *lista, int X){
    compra aux;
    aux.compra_id = -1;  //Caso nao haja o id de busca, o campo product.id do objeto falso retornara -1, esse reconhecimento é feito no main()
    for (int i = 0; i < validosCompra; i++){
        if(lista[i].compra_id == X){
            return lista[i];
        }
    }
    return aux; //apenas se nao encontrar
}

#endif
