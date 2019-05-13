#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <locale.h>

using namespace std;
#include "crudProduto.h"
#include "crudCategoria.h"
#include "crudCliente.h"
//#include "crudCompra.h"
#include "procedimentosHash.h"

int main(){
    setlocale(LC_ALL, "");

    int menu, idToFind = -1, subMenu;

	produto *produtos, auxProdutos;
	categoria *categorias, auxCategoria;
	cliente *clientes, auxCliente;
	//compra *compras, auxCompra;

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

		// compras = 0;
		// indiceCompras();
		// compras = openFileCompras();

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
						updateProduto(createProduto());
					break;

            		case 2:	//Categoria
						updateCategoria(create_categoria());
					break;

            		case 3:	//Cliente
						updateCliente(create_cliente());
					break;

            		case 4:	//Compra
						//upadateCompras(create_compra);
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
						alteraFileProduto(indexProduto, idToFind);
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
						// printf("(Compra)Alteracao no ID: ");
						// cin >> idToFind;
						// fflush(stdin);
						// alteraFileCompra(indexCompra, idToFind);
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
						alteraFileProduto(indexProduto, idToFind, true);
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
						// printf("(Compra)Exclusao no ID: ");
						// cin >> idToFind;
						// fflush(stdin);
						// alteraFileCompra(indexCompra, idToFind, true);
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
							Imprimir_pesquisaProduto(auxProdutos);
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
						// printf("(Compra)Pesquisa no ID: ");
						// cin >> idToFind;
						// auxCompra = PesquisarCompra(compras, idToFind);
						// if(aux.compra_id == -1){
						// 	printf("Produto não encontrado.\n");
						// } else {
						// 	Imprimir_pesquisaCompra(auxCompra);
						// }
            		break;

				}
            break;
        }
    } while (menu != 5);

return 0;
}
