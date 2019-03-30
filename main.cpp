#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

struct data{

    int product_id;
    char name[20];
    char description[25];
    float price;
    int quantity;
    char source[15];

};

void opc_create(){

    bool repeat = true;
    data toCreate;
    toCreate.name = "";

    while( repeat  ){

        printf("Nome do produto: ");

        cin >> toCreate.name;
        cout <<  toCreate.name;

        if(toCreate.name != ""){
            cout <<  toCreate.name;
            repeat = false;
        }
    }
    repeat = true;
    toCreate.description = "";
    while(repeat){

        printf("\nDescri��o: ");
        cin >> toCreate.description;
        cout <<  toCreate.description;
        if(toCreate.description != ""){
            cout <<  toCreate.description;
            repeat = false;
        }
    }
    //price
    repeat = true;
    toCreate.price = 0.0;
    while(repeat){

        printf("\nDescri��o: ");
        cin >> toCreate.price;
        repeat = false;
    }

    //qty
    repeat = true;
    toCreate.quantity = 0;
    while(repeat){

        printf("\nDescri��o: ");
        cin >> toCreate.quantity;

        repeat = false;

    }
    //type
    repeat = true;
    toCreate.type = "";
    while(repeat){

        printf("\nDescri��o: ");
        cin >> toCreate.type;
        if(toCreate.type!= ""){
            repeat = false;
        }
    }
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
    cout << "" << endl;
    //opc_create();
    data aux = create();
    cout<< "\n\n Impressao: \n";
    print(aux);
    update(aux);

return 0;
}
