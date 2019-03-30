#include <iostream>

#include <stdlib.h>

#include <stdio.h>

#include <iostream>

#include <string>

using namespace std;

struct data{

    int product_id;
    string name;
    string description;
    float price;
    int quantity;
    string type;

};

data * openAndParse(){

}

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

        printf("\nDescrição: ");
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

        printf("\nDescrição: ");
        cin >> toCreate.price;
        repeat = false;
    }

    //qty
    repeat = true;
    toCreate.quantity = 0;
    while(repeat){

        printf("\nDescrição: ");
        cin >> toCreate.quantity;

        repeat = false;

    }
    //type
    repeat = true;
    toCreate.type = "";
    while(repeat){

        printf("\nDescrição: ");
        cin >> toCreate.type;
        if(toCreate.type!= ""){
            repeat = false;
        }
    }
}

void create(){


}

void read(){

}

void update(){

}

void deleted(){

}

int main(){
    setlocale(LC_ALL,"portuguese");
    cout << "" << endl;
    opc_create();
    return 0;
}
