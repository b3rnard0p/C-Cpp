#include <iostream>
using namespace std;

#include "funcoes.h"

int main() {
    int dia, mes, ano;

    cout << "Digite o dia: ";
    cin >> dia;

    cout << "Digite o mês: ";
    cin >> mes;

    cout << "Digite o ano: ";
    cin >> ano;

    if (isDataValida(dia, mes, ano)) {
        cout << "A data é válida." << endl;
    } else {
        cout << "A data não é válida." << endl;
    }

    return 0;
}
