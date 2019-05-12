#ifndef CRUDCLIENTE_INCLUDED
#define CRUDCLIENTE_INCLUDED
//struct categoria;

int indexCliente = 0;
int validosCliente = 0;

struct cliente {
    int cliente_id;
    char nomeCliente[30];
    char emailCliente[50];
};

int indiceCliente (){  //Retorna o valor do indice

    int x = 0;
    char aux[100];
    FILE *arq = fopen("dataCliente.txt", "r+");
        if(arq == NULL){
            return x;
        } else {
            while( !feof ( arq ) ) {
                fscanf(arq, "%[^\n]\n", aux);   // Passa pelo arquivo
                x++;
            }
        }
    fclose(arq);
    indexCliente = x;
    return x;
}

cliente create_cliente(int id = -1){

    cliente aux;
    if(id >= 0){
        aux.cliente_id = id;
    } else{
        aux.cliente_id = indiceCliente();
    }

    cout<< "\tID da categoria: " << aux.cliente_id << endl;

    //fflush(stdin);
    cout<< "Nome do cliente: ";
    gets(aux.nomeCliente);

    cout<< "Email do cliente: ";
    gets(aux.emailCliente);
    cout << endl;

return aux;

}

void updateCliente(cliente aux){

    FILE *arq = fopen("dataCliente.txt", "a+");
    if (arq == NULL) {
        cout<<"\n\tErro na Leitura/Gravacao do arquivo!";
    }else{
        fprintf(arq, "%i\t%s\t%s\n",aux.cliente_id, aux.nomeCliente, aux.emailCliente);
    }
    fclose(arq);
}

void Imprimir_pesquisaCliente(cliente toShow){

printf("\nCliente ID: %i\n Nome Cliente: %s\n Email Cliente: %s\n\n",
        toShow.cliente_id, toShow.nomeCliente, toShow.emailCliente);

}

cliente *openFileCliente(int n){
    validosCliente = 0;
    cliente * toLoad = (cliente *)calloc(n, sizeof(cliente));
    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("dataCliente.txt", "r+");
        int i = 0;
        if(arq){
            while( !feof(arq) ){
                fscanf
                    ( arq, "%i\t%[^\t]\t%[^\n]\n",
                     &toLoad[i].cliente_id, &toLoad[i].nomeCliente, &toLoad[i].emailCliente);
                if(!(toLoad[i].cliente_id <= -1)){//id negativo serve como lapide
                    validosCliente++;
                    i++;
                }else{
                    //Imprimir_pesquisaCliente(toLoad[i]);
                }
            }
        }
        fclose(arq);
    }
    return toLoad;
}

cliente *alteraFileCliente(int n, int id, bool opcExclusao = false){
    validosCliente = 0;
    bool finded = false;
    cliente * toLoad = (cliente *)calloc(n, sizeof(cliente));

    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("dataCliente.txt", "r+");
        int i = 0;
        if(arq){
            while( !feof(arq) ){
                fscanf
                    ( arq, "%i\t%[^\t]\t%[^\n]\n",
                     &toLoad[i].cliente_id, &toLoad[i].nomeCliente, &toLoad[i].emailCliente);
                if(!(toLoad[i].cliente_id <= -1)){//id negativo serve como lapide
                        if(toLoad[i].cliente_id == id){
                            //anda no arquivo
                            finded = true;
                            cout << "Produto pra ser alterado:\n";
                            Imprimir_pesquisaCliente(toLoad[i]);
                            if(!opcExclusao){
                                toLoad[i] = create_cliente(id);
                                toLoad[i].cliente_id = id;
                            }
                            if(opcExclusao){
                                toLoad[i].cliente_id = -2;
                            }
                        }
                    validosCliente++;
                    i++;
                }else{
                    i++;
                }
            }
        }
        fclose(arq);
        FILE *arqNovo = fopen("dataCliente.txt", "w+");
        int a = 0;
        while(a < i){
            fprintf(arqNovo, "%i\t%s\t%s\n",
                    toLoad[a].cliente_id, toLoad[a].nomeCliente, toLoad[a].emailCliente);
            a++;
        }
        fclose(arqNovo);
    }

    if(!finded){
        cout<<"Produto não encontrado.\n\n";
    }
    return toLoad;
}

cliente PesquisarCliente(cliente *lista, int X){
    cliente aux;
    aux.cliente_id = -1;  //Caso nao haja o id de busca, o campo product.id do objeto falso retornara -1, esse reconhecimento é feito no main()
    for (int i = 0; i < validosCliente; i++){
        if(lista[i].cliente_id == X){
            return lista[i];
        }
    }
    return aux; //apenas se nao encontrar 
}

#endif
