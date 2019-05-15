#ifndef CRUDCARRINHO_H_INCLUDED
#define CRUDCARRINHO_H_INCLUDED

int indexCarrinho = 0, validosCarrinho = 0;

struct itemComprado {
    int carrinho_id;
    int idCompra;
    int idProduto;
    int QtdProduto;  //=  insercao de produtos comprados, cria arquivo e retorna total    -->ex: produtoComprado()
};

int indiceCarrinho (){  //Retorna o valor do indice

    int x = 0;
    char aux[100];
    FILE *arq = fopen("dataItemComprado.txt", "r+");
        if(arq == NULL){
            return x;
        } else {
            while( !feof ( arq ) ) {
                fscanf(arq, "%[^\n]\n", aux);   // Passa pelo arquivo
                x++;
            }
        }
    fclose(arq);
    indexCarrinho = x;
    return x;
}

itemComprado create_carrinhoInserir(int idProduto, int idCompra){
    itemComprado aux;

    aux.carrinho_id = indiceCarrinho();
    aux.idCompra = idCompra;
    aux.idProduto = idProduto;

    fflush(stdin);
    cout<< "Qantidade desse produto: ";
    cin>> aux.QtdProduto;
    fflush(stdin);

return aux;
}

itemComprado create_carrinho(int id, int compra, int produto){

    itemComprado aux;

    aux.carrinho_id = id;
    aux.idCompra = compra;
    aux.idCompra = idCliente;
    aux.idProduto = produto;

    fflush(stdin);
    cout<< "Qantidade desse produto: ";
    cin>> aux.QtdProduto;
    fflush(stdin);

return aux;

}

void updateCarrinho(itemComprado aux){

    FILE *arq = fopen("dataItemComprado.txt", "a+");
    if (arq == NULL) {
        cout<<"\n\tErro na Leitura/Gravacao do arquivo!";
    }else{
        fprintf(arq, "%i\t%i\t%i\t%i\n",aux.carrinho_id, aux.idCompra, aux.idProduto, aux.QtdProduto);
    }
    fclose(arq);
}

void Imprimir_pesquisaCarrinho(itemComprado toShow){

    printf("\n\tCompra ID: %i\n Cliente ID: %i\n Data itemComprado: %i\n Total itemComprado: %i\n\n",
            toShow.carrinho_id, toShow.idCompra, toShow.idProduto, toShow.QtdProduto);

}

itemComprado *openFileCarrinho(int n){
    validosCarrinho = 0;
    itemComprado * toLoad = (itemComprado *)calloc(n, sizeof(itemComprado));
    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("dataItemComprado.txt", "r+");
        int i = 0;
        if(arq){
            while( !feof(arq) ){
                fscanf
                    ( arq, "%i\t%i\t%i\t%i\n",
                     &toLoad[i].carrinho_id, &toLoad[i].idCompra, &toLoad[i].idProduto, &toLoad[i].QtdProduto);
                if(!(toLoad[i].carrinho_id <= -1)){//id negativo serve como lapide
                    validosCarrinho++;
                    i++;
                }else{
                    //Imprimir_pesquisaCarrinho(toLoad[i]);
                }
            }
        }
        fclose(arq);
    }
    return toLoad;
}

itemComprado *alteraFileCarrinho(int n, int id, produto *produtos, bool opcExclusao = false){
    validosCarrinho = 0;
    bool finded = false, cond = false;
    itemComprado * toLoad = (itemComprado *)calloc(n, sizeof(itemComprado));
    int idProduto;
    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("dataItemComprado.txt", "r+");
        int i = 0;
        if(arq){
            while( !feof(arq) ){
                fscanf
                    ( arq, "%i\t%i\t%i\t%i\n",
                     &toLoad[i].carrinho_id, &toLoad[i].idCompra, &toLoad[i].idProduto, &toLoad[i].QtdProduto);
                if(!(toLoad[i].carrinho_id <= -1)){//id negativo serve como lapide
                        if(toLoad[i].idCompra == id){
                            //anda no arquivo
                            finded = true;
                            cout << "Carrinho pra ser alterado:\n";
                            Imprimir_pesquisaCarrinho(toLoad[i]);
                            if(!opcExclusao){
                            cout<< "Qual o id do produto a ser comprado: ";
                                do{
                                    cin>> idProduto;
                                    if (pesquisaProduto(produtos, idProduto)){
                                        toLoad[i] = create_carrinho(toLoad[i].carrinho_id , id, idProduto);
                                        toLoad[i].carrinho_id = id;
                                        cond = true;
                                    } else {
                                        cout<< "ID de produto nao encontrado, tente outro: ";
                                    }
                                } while (!cond);
                            }
                            if(opcExclusao){
                                toLoad[i].carrinho_id = -2;
                            }
                        }
                    validosCarrinho++;
                    i++;
                }else{
                    i++;
                }
            }
        }
        fclose(arq);
        FILE *arqNovo = fopen("dataItemComprado.txt", "w+");
        int a = 0;
        while(a < i){
            fprintf(arqNovo, "%i\t%i\t%i\t%i\n",
                    toLoad[a].carrinho_id, toLoad[a].idCompra, toLoad[a].idProduto, toLoad[a].QtdProduto);
            a++;
        }
        fclose(arqNovo);
    }

    if(!finded){
        cout<<"Produto não encontrado.\n\n";
    }
    return toLoad;
}

itemComprado PesquisarCompra(itemComprado *lista, int X){
    itemComprado aux;
    aux.carrinho_id = -1;  //Caso nao haja o id de busca, o campo product.id do objeto falso retornara -1, esse reconhecimento é feito no main()
    for (int i = 0; i < validosCarrinho; i++){
        if(lista[i].carrinho_id == X){
            return lista[i];
        }
    }
    return aux; //apenas se nao encontrar
}

#endif
