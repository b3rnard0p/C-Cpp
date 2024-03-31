#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#include"Util.h"

int main() {
    int N = 10; 
    int M = 5;  

    vector<Lista*> listas(N); 

    srand(time(NULL));


    for (int i = 0; i < N; ++i) {
        Lista* lista = NULL;
        for (int j = 0; j < M; ++j) {
            lista = inserir(rand() % 100 + 1, lista);
        }
        listas[i] = lista;
    }

    for (int i = 0; i < N; ++i) {
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
