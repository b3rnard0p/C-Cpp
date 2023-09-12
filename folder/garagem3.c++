#include<iostream>
#include<string>
#include<stdlib.h>
#include <ctime>


#define TAM 10

using namespace std;

#include"struct3.h"
#include"util3.h"


int main(){
	Veiculo vetor[TAM];

    inicializarVetor (vetor, TAM);
	int opcao, quantidadeCarros = 0;

	do{
		
		system ("cls");
		cout << "MENU\n";
		cout << "1 - Entrar na garagem\n";
		cout << "2 - Listar veiculos\n";
		cout << "3 - Remover da garagem\n";
		cout << "4 - Sair\n";
		cout << "Opcao: ";
		cin >> opcao;
	
		
		switch(opcao){
			case 1:
				quantidadeCarros = entrarGaragem(vetor,TAM, quantidadeCarros);
				break;
			case 2:
			    listarGaragem(vetor, TAM, quantidadeCarros);
			    break;
			case 3:
            quantidadeCarros = sairGaragem(vetor,TAM, quantidadeCarros);
				cout << "Retirada de veiculo\n";
				break;
			case 4:
				break;
				default:
					cout << "Opcao invalida\n";
				
		}
		system("pause");
	}while (opcao !=  4);
	
	
	return 1;
}