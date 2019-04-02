#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <locale.h>
using namespace std;

int index = 0, validos = 0;

struct data{

    int product_id;
    char name[20];
    char description[25];
    float price;
    int quantity;
    char source[15];

};

data * openAndParse(){

}

int indice (){  //Retorna o valor do indice

    int x = 0;
    char aux[100];
    FILE *arq = fopen("data.txt", "r+");
        if(arq == NULL){
            return x;
        } else {
            while( !feof ( arq ) ) {
                fscanf(arq, "%[^\n]\n", aux);   // Passa pelo arquivo
                x++;
            }
        }
    fclose(arq);
    index = x;
    return x;
}

data create(int id = -1){

    data aux;
    if(id >= 0){
        aux.product_id = id;
    } else{
        aux.product_id = indice();
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

void print (data x){

    cout<< "ID: " << x.product_id << endl;
    cout<< "Nome: " << x.name << endl;
    cout<< "Descricao: " << x.description << endl;
    cout<< "Preco: " << x.description << endl;
    cout<< "Origem: " << x.source << endl;

}

void update(data aux){

    //data aux = create();
    FILE *arq = fopen("data.txt", "a+");
    if (arq == NULL) {
        cout<<"\n\tErro na Leitura/Gravacao do arquivo!";
    }else{
        fprintf(arq, "%i\t%s\t%s\t%f\t%i\t%s\n",aux.product_id, aux.name, aux.description, aux.price, aux.quantity, aux.source);
    }
    fclose(arq);
}

void deleteItem(int id){
 return ;
}


//=============================================== PROCEDIMENTOS PARA HASH

struct CelulaH{
    data cellData;
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

void InserirH(ListaH *lista, data x){


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

data PesquisarH(ListaH *lista, int X){
    data falso = {};
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

void InserirHash(ListaH *tabela[], int N, data x){

    int pos = FuncaoHash(x.product_id , N);
    InserirH(tabela[pos], x);

}

data PesquisarHash(ListaH *tabela[], int N, int X){
    int contpesq=0;
    int pos = FuncaoHash(X,N);
    data consulta = PesquisarH(tabela[pos], X);
    contpesq++;
    //cout<<"Buscas necessárias na tabela: "<<contpesq<<endl;
    return consulta;

    /*
    if(consulta != {0,0,0,0,0,0,0,0,0,0,0,0})
        return pos;
    return -1;
*/
}

void ImprimirHash(ListaH *tabela[], int N){
    int j=0;
    for(int i=0; i<N; i++){
        printf("%i|\t", i);
        ImprimirH(tabela[i]);
    }
    printf("\n====================\n");
}

//===============================================
void Imprimir_pesquisa(data toShow){

        printf("\n\nProduct_id: %i\n Nome: %s\n Descricao: %s\n Preco: %f\n Quantidade: %i\n Origem: %s\n\n",
                            toShow.product_id, toShow.name, toShow.description, toShow.price,
                            toShow.quantity, toShow.source);

}

data *openFile(int n){
    validos = 0;
    data * toLoad = (data *)calloc(n, sizeof(data));
    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("data.txt", "r+");
        int i = 0;
        //cout << "Serão pesquisados " << n << endl;
        if(arq){
            while( !feof(arq) ){
                fscanf
                    ( arq, "%i\t%[^\t]\t%[^\t]\t%f\t%i\t%[^\n]\n",
                     &toLoad[i].product_id, &toLoad[i].name, &toLoad[i].description, &toLoad[i].price,&toLoad[i].quantity, &toLoad[i].source);
                if(!(toLoad[i].product_id <= -1)){//id negativo serve como lapide
                    validos++;
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

data *alteraFile(int n, int id, bool opcExclusao = false){
    validos = 0;
    bool finded = false;
    data * toLoad = (data *)calloc(n, sizeof(data));
    if(toLoad == NULL){
        cout << "não há memoria suficiente";
    } else {
        FILE *arq = fopen("data.txt", "r+");
        int i = 0;
        //cout << "Serão pesquisados " << n << endl;
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
                            Imprimir_pesquisa(toLoad[i]);
                            if(!opcExclusao){
                                toLoad[i] = create(id);
                                toLoad[i].product_id = id;
                            }
                            if(opcExclusao){
                                toLoad[i].product_id = -2;
                            }
                        }
                    validos++;
                    i++;
                }else{
                    i++;
                    //Imprimir_pesquisa(toLoad[i]);
                }
            }
        }
        fclose(arq);
        FILE *arqNovo = fopen("data.txt", "w+");
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

int main(){
    setlocale(LC_ALL, "");
    /*
    if(setlocale(LC_ALL, "Portuguese") == NULL) {
        printf("error while setlocale()\n");
    }
    */
    int menu, idToFind = -1;
    data *v, aux;

    //data aux = create();
    //print(aux);
    int fator=32;    // potencia de 2 abaixo do tamanho total (total= 12800 -> potencia de 2 mais proxima 65536 -> numero primo abaixo 65521), como Sedgewick sugere
    ListaH **TabelaHash = (ListaH **)calloc(fator,sizeof(ListaH *));
    InicializarHash(TabelaHash, fator);

    indice();
    v = openFile(index);

    do{
        printf("\tMenu:\n1 - Inclusão\n2 - Alteração\n3 - Exclusão\n4 - Pesquisa\n5 - Sair\n-->Entrada: ");
        cin>>menu;
        cout << endl;
        fflush(stdin);
        if(menu == 5){
            break;
        }
        if(menu < 1 || menu > 5){
            cout<<"\t\tOpcao invalida, digite novamente...\n";
        }

        v = 0;
        indice();
        v = openFile(index);
        InicializarHash(TabelaHash, fator);
        for(int i=0; i< validos; i++){
            InserirHash(TabelaHash, fator, v[i]);
        }

        switch(menu){
            case 1: // Inclusao
            {
                //cout<<"Inclusão\n";
                update(create());
                //openFile(index);
            }
            break;

            case 2: //Alteracao

                //cout<<"Alteração no ID: ";
                printf("Alteração no ID: ");
                cin >> idToFind;
                fflush(stdin);
                alteraFile(index, idToFind);

            break;

            case 3: //Exclusao

                cout<<"Exclusãono ID: ";
                cin >> idToFind;
                fflush(stdin);
                alteraFile(index, idToFind, true);


            break;

            case 4://Pesquisa

                cout<<"Pesquisa no ID: ";
                cin >> idToFind;

                aux=PesquisarHash(TabelaHash, fator, idToFind);
                //Imprimir_pesquisa(aux);
                //cout<<endl<<aux.product_id<<endl<<endl;

                if(aux.product_id == 0){
                    printf("Produto não encontrado.\n");
                } else {
                    Imprimir_pesquisa(aux);
                }

            break;
        }

    }while(menu != 5);

return 0;
}
