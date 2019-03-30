#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

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

    int x = 0, aux;
    FILE *arq = fopen("data.txt", "r");
        if(arq == NULL){
            return x;
        } else {
            while( !feof ( arq ) ) {
                fscanf(arq, "%[^\n]\n", aux);   // Passa pelo arquivo
                x++;
            }
        }
    fclose(arq);
    return x;
}

data create(){

    data aux;
    aux.product_id = indice();
    cout<< "\tProduto: " << aux.product_id << endl;

    cout<< "Nome do produto: ";
    gets(aux.name);

    cout<< "Descricao do produto: ";
    gets(aux.description);

    cout<< "Preco do produto: ";
    cin>> aux.price;

    cout<< "Quantidade do produto: ";
    cin>> aux.quantity;

    cin.ignore();
    cout<< "Origem do produto: ";
    gets(aux.source);

return aux;

}

void print (data x){

    cout<< "ID: " << x.product_id << endl;
    cout<< "Nome: " << x.name << endl;
    cout<< "Descricao: " << x.description << endl;
    cout<< "Preco: " << x.description << endl;
    cout<< "Origem: " << x.source << endl;

}

void read(){

}

void update(data aux){

    FILE *arq = fopen("data.txt", "a+");
    if (arq == NULL) {
        cout<<"\n\tErro na Leitura/Gravacao do arquivo!";
    }else{
        fprintf(arq, "%i\t%s\t%s\t%f\t%i\t%s\n",aux.product_id, aux.name, aux.description, aux.price, aux.quantity, aux.source);
    }
    fclose(arq);
}

void deleted(){

}

int main(){
    setlocale(LC_ALL,"portuguese");
    int menu;
    do{
        printf("\tMenu:\n1 - Inclusao\n2 - Alteracao\n3 - Exclusao\n4 - Pesquisa\n5 - Sair\n\n");
        cin>>menu;
        if(menu == 5){
            break;
        }
        if(menu < 1 || menu > 5){
            cout<<"\t\tOpcao invalida, digite novamente...\n";
        }

        switch(menu){
            case 1: // Inclusao
                cout<<"Inclusao\n";
            break;

            case 2: //Alteracao
                cout<<"Alteracao\n";
            break;

            case 3: //Exclusao
                cout<<"Exclusao\n";
            break;

            case 4: //Pesquisa
                cout<<"Pesquisa\n";
            break;
        }

    }while(menu != 5);

return 0;
}
