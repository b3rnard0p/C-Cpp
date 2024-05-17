#include <iostream>

using namespace std;

#include "Metodos.h"

int main() {
    int escolha, n, k;

    // Menu de escolha
    cout << "Escolha o que deseja calcular:" << std::endl;
    cout << "1 - Combinação (C(n, k))" << std::endl;
    cout << "2 - Arranjo (A(n, k))" << std::endl;
    cout << "Opçaoo: ";
    cin >> escolha;

    // Solicita ao usuário os valores de n e k
    cout << "Digite o valor de n: ";
    cin >> n;
    cout << "Digite o valor de k: ";
    cin >> k;

    if (escolha == 1) {
        // Calcula e exibe a combinaçãoo
        cout << "Combinação C(" << n << ", " << k << ") = " << combinacao(n, k) << std::endl;
    } else if (escolha == 2) {
        // Calcula e exibe o arranjo
        cout << "Arranjo A(" << n << ", " << k << ") = " << arranjo(n, k) << std::endl;
    } else {
        cout << "Opção inválida." << std::endl;
    }

    return 0;
}

