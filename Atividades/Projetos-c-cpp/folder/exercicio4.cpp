#include <iostream>
using namespace std;

#include "funcoes.h"

int main() {
    int anoAtual, anoNascimento;

    cout << "Digite o ano atual: ";
    cin >> anoAtual;

    cout << "Digite o ano de nascimento: ";
    cin >> anoNascimento;

    int idade = calcularIdade(anoAtual, anoNascimento);
    cout << "A idade é: " << idade << " anos" << endl;

    return 0;
}
