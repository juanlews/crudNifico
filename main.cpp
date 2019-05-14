#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <locale.h>

using namespace std;

int idTemp = -1, idCliente = -1;

#include "crudCategoria.h"
#include "crudProduto.h"
#include "crudCliente.h"
#include "crudCompra.h"
#include "procedimentosHash.h"

int main(){
    setlocale(LC_ALL, "");

    int menu, idToFind = -1, subMenu;
    bool cond = 0;

	produto *produtos, auxProdutos;
	categoria *categorias, auxCategoria;
	cliente *clientes, auxCliente;
	compra *compras, auxCompra;

	int fator=32;
    ListaH **TabelaHash = (ListaH **)calloc(fator,sizeof(ListaH *));
    InicializarHash(TabelaHash, fator);

    do{
        printf("====> Menu <====\n1- Inclusao\n2- Alteracao\n3- Exclusao\n4- Pesquisa\n5- Sair\n-->Entrada: ");
        cin >> menu;
        cout << endl;
        fflush(stdin);
        if(menu == 5){
            break;
        }
        if(menu < 1 || menu > 5){
            cout << "\tOpcao invalida, digite novamente...\n";
        }

            //Inicia cruds
		produtos = 0;
        indiceProduto();
        produtos = openFileProduto(indexProduto);
		InicializarHash(TabelaHash, fator);
        for(int i = 0; i < validosProduto; i++){
            InserirHash(TabelaHash, fator, produtos[i]);
        }

		categorias = 0;
        indiceCategoria();
		categorias = openFileCategorias(indexCategoria);

		clientes = 0;
		indiceCliente();
		clientes = openFileCliente(indexCliente);

		compras = 0;
		indiceCompra();
		compras = openFileCompra(indexCompra);

        switch(menu){
            case 1: // Inclusao

            	cout << "Digite 1 para incluir um produto, 2 para categoria, 3 para cliente ou 4 para compra: ";
            	cin >> subMenu;
            	fflush(stdin);

				if(subMenu < 1 || subMenu > 4){
					cout << "\tOpcao invalida, digite novamente...\n";
				}

            	switch(subMenu){
            		case 1:	//Produto
                        if(indexCategoria == 0){    //Verifica se ha alguma categoria cadastrada para só assim cadasrtar um produto
                            printf("Antes de cadastrar um produto, cadastre uma categoria!\n");
                        } else {
                            idTemp = -1;
                            cond = 0;
                            cout<< "Qual o id da categoria do produto: ";
                            do{
                                cin>> idTemp;
                                if (pesquisaCategoria(categorias, idTemp)){
						            updateProduto(createProduto());
                                    cond = true;
                                } else {
                                    cout<< "ID de categoria nao encontrado, tente outro: ";
                                }
                            } while (!cond);
                        }
					break;

            		case 2:	//Categoria
						updateCategoria(create_categoria());
					break;

            		case 3:	//Cliente
						updateCliente(create_cliente());
					break;

            		case 4:	//Compra
						if(indexCliente == 0){    //Verifica se ha algum cliente cadastrado para compra
                            printf("Antes de comprar um produto, cadastre um cliente!\n");
                        } else {
                            idCliente= -1;
                            cond = 0;
                            cout<< "Qual o id do cliente para compra: ";
                            do{
                                cin>> idCliente;
                                if (pesquisaCliente(clientes, idCliente)){
						            updateCompra(create_compra());
                                    cond = true;
                                } else {
                                    cout<< "ID de cliente nao encontrado, tente outro: ";
                                }
                            } while (!cond);
                        }
					break;

					}
            break;

            case 2: //Alteracao

				cout << "Digite 1 para alterar um produto, 2 para categoria, 3 para cliente ou 4 para compra: ";
            	cin >> subMenu;
            	fflush(stdin);

				if(subMenu < 1 || subMenu > 4){
					cout << "\tOpcao invalida, digite novamente...\n";
				}

            	switch(subMenu){
            		case 1:	//Produto
						printf("(Produto)Alteracao no ID: ");
						cin >> idToFind;
						fflush(stdin);
						alteraFileProduto(indexProduto, idToFind, categorias);
            		break;

            		case 2:	//Categoria
						 printf("(Categoria)Alteracao no ID: ");
						 cin >> idToFind;
						 fflush(stdin);
						 alteraFileCategorias(indexCategoria, idToFind);
            		break;

            		case 3:	//Cliente
						printf("(Cliente)Alteracao no ID: ");
						cin >> idToFind;
						fflush(stdin);
						alteraFileCliente(indexCliente, idToFind);
            		break;

            		case 4:	//Compra
						printf("(Compra)Alteracao no ID: ");
						cin >> idToFind;
						fflush(stdin);
						alteraFileCompra(indexCompra, idToFind, clientes);
            		break;

				}
            break;

            case 3: //Exclusao

            	cout << "Digite 1 para excluir um produto, 2 para categoria, 3 para cliente ou 4 para compra: ";
            	cin >> subMenu;
            	fflush(stdin);

				if(subMenu < 1 || subMenu > 4){
					cout << "\tOpcao invalida, digite novamente...\n";
				}

            	switch(subMenu){
            		case 1:	//Produto
						printf("(Produto)Exclusao no ID: ");
						cin >> idToFind;
						fflush(stdin);
						alteraFileProduto(indexProduto, idToFind, categorias, true);
					break;

            		case 2:	//Categoria
						 printf("(Categoria)Exclusao no ID: ");
						 cin >> idToFind;
						 fflush(stdin);
						 alteraFileCategorias(indexCategoria, idToFind, true);
					break;

            		case 3:	//Cliente
						printf("(Cliente)Exclusao no ID: ");
						cin >> idToFind;
						fflush(stdin);
						alteraFileCliente(indexCliente, idToFind, true);
					break;

            		case 4:	//Compras
						printf("(Compra)Exclusao no ID: ");
						cin >> idToFind;
						fflush(stdin);
						alteraFileCompra(indexCompra, idToFind, clientes, true);
					break;

				}
            break;

            case 4://Pesquisa

			  	cout << "Digite 1 para pesquisar um produto, 2 para categoria, 3 para cliente ou 4 para compra: ";
            	cin >> subMenu;
            	fflush(stdin);

				if(subMenu < 1 || subMenu > 4){
					cout << "\tOpcao invalida, digite novamente...\n";
				}

            	switch(subMenu){
            		case 1:  //Produto
						printf("(Produto)Pesquisa no ID: ");
						cin >> idToFind;
						auxProdutos = PesquisarHash(TabelaHash, fator, idToFind);
						if(auxProdutos.product_id == -1){
							printf("Produto não encontrado.\n");
						} else {
                            auxCategoria = PesquisarCategoria(categorias, auxProdutos.product_categoria);
							Imprimir_pesquisaProduto(auxProdutos, auxCategoria.nomeCategoria);
						}
            		break;

            		case 2:	//Categoria
                        printf("(Categoria)Pesquisa no ID: ");
                        cin >> idToFind;
                        auxCategoria = PesquisarCategoria(categorias, idToFind);
						if(auxCategoria.categoria_id == -1){
                            printf("Produto não encontrado.\n");
                        } else {
                            Imprimir_pesquisaCategoria(auxCategoria);
						}
            		break;

            		case 3:	//Cliente
						printf("(Cliente)Pesquisa no ID: ");
						cin >> idToFind;
						auxCliente = PesquisarCliente(clientes, idToFind);
						if(auxCliente.cliente_id == -1){
							printf("Produto não encontrado.\n");
						} else {
							Imprimir_pesquisaCliente(auxCliente);
						}
            		break;

            		case 4:	//Compra
						printf("(Compra)Pesquisa no ID: ");
						cin >> idToFind;
						auxCompra = PesquisarCompra(compras, idToFind);
						if(auxCompra.compra_id == -1){
							printf("Produto não encontrado.\n");
						} else {
							Imprimir_pesquisaCompra(auxCompra);
						}
            		break;

				}
            break;
        }
    } while (menu != 5);

return 0;
}
