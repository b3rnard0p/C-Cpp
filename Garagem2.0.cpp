#include<iostream>
#include<string>
#include<stdlib.h>

#define TAM 10

using namespace std;

#include"struct.h"
#include"util.h"

int main(){
	Veiculo vetor[TAM];
    inicializarVetor (vetor, TAM);
	int opcao;
	string placa, hora;
	int quantidadeCarros = 0;
	bool carroLocalizado;
	
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
				cout << "Cadastro de veiculo\n";

				if(quantidadeCarros == TAM){
					cout << "Garagem lotada\n";
				}
				else{
     				while (true){
						cout << "Informe a placa em Maiusculo";
						cin >> placa;
						if(placa.length() == 7){
							break;
						}
						else{
							cout << "Digite corretamente a placa\n";
						}
					}		
					while (true){
						cout << "Informe a hora de entrada[hh/mm]:";
						cin >> hora;
						if(hora.length() == 5){
							break;
						}
						else{
							cout << "Digite corretamente a hora\n";
						}
					}
					carroLocalizado = false;
					for(int i=0;i<TAM ;i++){
						if(placa== vetor[i].placa){
							cout << "Carro ja na garagem\n";
							carroLocalizado = true;
							break;
						}
					}
					
					if(!carroLocalizado){
						for(int i=0;i<TAM ;i++){
							if (vetor[i].placa == "") {
								vetor[i].placa = placa;
								vetor[i].horaEntrada = hora;
								quantidadeCarros++;
								break;
							} 
						}
					}
				}
				break;
			case 2:
				cout << "Listagem de veiculo\n";
				if(quantidadeCarros==0){
				cout << "Garagem vazia\n";
			}
			else{
				for(int i=0;i<TAM;i++){
					if(vetor[i].placa != ""){
						cout << "Placa: " << vetor[i].placa << endl;
					}
				}
			}
			    break;
			case 3:
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
