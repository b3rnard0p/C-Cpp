#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#include"Util.h"

int main() {
    int numListas, tamanhoLista;
    cout << "Quantas listas deseja criar? ";
    cin >> numListas;
    cout << "Qual o tamanho de cada lista? ";
    cin >> tamanhoLista;

    vector<Lista *> listas;
    srand(time(NULL));

    for (int i = 0; i < numListas; ++i) {
        listas.push_back(criarLista(tamanhoLista));
    }

    for (int i = 0; i < numListas; ++i) {
        cout << "Lista " << i + 1 << ": ";
        exibir(listas[i]);
        cout << endl;
    }

    vector<int> numerosComuns;
    vector<int> numerosUnicos;
    localizarComunsEUnicos(listas, numerosComuns, numerosUnicos);

    cout << "Números comuns em todas as listas: ";
    for (int num : numerosComuns) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Números únicos em apenas uma das listas: ";
    for (int num : numerosUnicos) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
