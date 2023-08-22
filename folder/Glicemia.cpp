//Menu: 
//1-Cadastrar medicao(Medida, Data e Hora), 
//2-Listar medicoes, 
//3-Calcular e mostrar media e mediana, 
//4-Sair 
//Opcao:.
//Estrutura: 
//String Data, 
//String Hora, 
//int valorMedicao.
//Observacao: Validar a medida da glicemia(10 a 600).

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int TAM = 100; 

#include"structt.h"
#include"utill.h"

int main() {
    Medicao medicoes[TAM];
    int numMedicoes = 0;
    int opcao;

    do {
        system("cls");
        cout << "MENU:\n";
        cout << "1 - Cadastrar medicao\n";
        cout << "2 - Listar medicoes\n";
        cout << "3 - Calcular e mostrar media e mediana\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarMedicao(medicoes, numMedicoes);
                break;
            case 2:
                listarMedicoes(medicoes, numMedicoes);
                break;
            case 3:
                calcularMediaMediana(medicoes, numMedicoes);
                break;
            case 4:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
        system("pause");
    } while (opcao != 4);

    return 0;
}



