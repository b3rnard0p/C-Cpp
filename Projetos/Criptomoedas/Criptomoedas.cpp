#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Struct.h"

#include "Metodos.h"

int main() {
    Criptomoeda* vetor = nullptr;
    int totalCriptomoedas = 0;
    int capacidade = 0; 

    carregarCriptomoedas(vetor, totalCriptomoedas, capacidade);

    int opcao;

    do {
        cout << "MENU" << endl;
        cout << "1 - Cadastrar Criptomoeda" << endl;
        cout << "2 - Atualizar Valor" << endl;
        cout << "3 - Remover Criptomoeda" << endl;
        cout << "4 - Listar Criptomoedas" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrar(vetor, totalCriptomoedas, capacidade);
                salvarCriptomoedas(vetor, totalCriptomoedas);
                break;
            case 2:
                atualizar(vetor, totalCriptomoedas);
                salvarCriptomoedas(vetor, totalCriptomoedas);
                break;
            case 3:
                remover(vetor, totalCriptomoedas);
                salvarCriptomoedas(vetor, totalCriptomoedas);
                break;
            case 4:
                listar(vetor, totalCriptomoedas);
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (opcao != 5);

    delete[] vetor; 

    return 0;
}
