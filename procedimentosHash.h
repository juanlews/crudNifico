#ifndef PROCEDIMENTOSHASH_INCLUDED
#define PROCEDIMENTOSHASH_INCLUDED
//=============================================== PROCEDIMENTOS PARA HASH

struct CelulaH{
    produto cellData;
    CelulaH *prox;
};

struct ListaH{
    CelulaH *inicio, *fim;
    int tam;
};

void InicializarH(ListaH *lista){

    lista->inicio = (CelulaH*) malloc(sizeof(CelulaH));
    lista->inicio->prox = NULL;

    lista->fim = lista->inicio;

    lista->tam = 0;
}

bool VaziaH(ListaH *lista){
    return lista->inicio == lista->fim;
}

void InserirH(ListaH *lista, produto x){


    CelulaH *temp = (CelulaH*) malloc(sizeof(CelulaH));
    temp->cellData = x;
    temp->prox = NULL;

    lista->fim->prox = temp;
    lista->fim = temp;


    lista->tam++;
}

void ImprimirH(ListaH *lista){
    for(CelulaH *temp = lista->inicio->prox; temp!=NULL; temp=temp->prox){
        printf(" %i -", temp->cellData.product_id);
    }
    printf("\n");
}

int TamanhoH(ListaH *lista){
    return lista->tam;
}

produto PesquisarH(ListaH *lista, int X){
    produto falso;
    falso.product_id = -1;  //Caso nao haja o id de busca, o campo product.id do objeto falso retornara -1, esse reconhecimento é feito no main()
    int contpesq=0;
    for(CelulaH *temp = lista->inicio->prox; temp!=NULL; temp=temp->prox){
        contpesq++;
        if(temp->cellData.product_id == X)
            //cout<<"Buscas necessárias na lista: "<<contpesq<<endl;
            return temp->cellData;
    }
    return falso;
}

int FuncaoHash(int X, int N){
    return X % N;
}

void InicializarHash(ListaH *tabela[], int N){

    for(int i=0; i<N; i++){
       tabela[i] = (ListaH*)malloc(sizeof(ListaH));
       InicializarH(tabela[i]);
    }
}

void InserirHash(ListaH *tabela[], int N, produto x){

    int pos = FuncaoHash(x.product_id , N);
    InserirH(tabela[pos], x);

}

produto PesquisarHash(ListaH *tabela[], int N, int X){
    int contpesq=0;
    int pos = FuncaoHash(X,N);
    produto consulta = PesquisarH(tabela[pos], X);
    contpesq++;
    //cout<<"Buscas necessárias na tabela: "<<contpesq<<endl;
    return consulta;
}

void ImprimirHash(ListaH *tabela[], int N){
    int j=0;
    for(int i=0; i<N; i++){
        printf("%i|\t", i);
        ImprimirH(tabela[i]);
    }
    printf("\n====================\n");
}

#endif