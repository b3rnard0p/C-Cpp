#include <iostream>
using namespace std;

#include "funcoes.h"

int main() {
    int numero;
    cout << "Digite um número inteiro: ";
    cin >> numero;

    if (ehPrimo(numero)) {
        cout << numero << " é primo." << endl;
    } else {
        cout << numero << " não é primo." << endl;
    }

    return 0;
}
