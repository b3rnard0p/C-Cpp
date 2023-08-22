//Menu: 
//1- Entrar na Garagem(Controle de duplicidade) 
//2- Listar Carros(Mostrae a placa,Data e hora de entrada 
//3- Sair da Garagem(Remover ve�culo e reorganizar o vetor 
//4-Sair 
//Op��o:.
//Estrutura: 
//String Placa[7], 
//String Data[10], 
//String Hora[5].
#include<iostream>
#include<string>

using namespace std;

#define TAM 10

#include"struct.h"

int main(){
	Veiculo vetor[TAM];
	int opcao;
	
	do{
		
		system ("cls");
		cout << "MENU\n";
		cout << "1 - Entrar na garagem\n";
		cout << "2 - Listar veiculos\n";
		cout << "3 - Remover da garagem\n";
		cout << "2 - Sair\n";
		cout << "Opção: ";
		cin >> opcao;
		system("pause");
		
		switch(opcao){
			case 1:
				cout << "Cadastro de veiculo\n";
				break;
			case 2:
				cout << "Listagem de veiculo\n";
			    break;
			case 3:
				cout << "Retirada de veiculo\n";
				break;
			case 4:
				break;
				default:
					cout << "Opção inválida\n";
				
		}
		
	}while (opcao !=  4);
	
	return 1;
}