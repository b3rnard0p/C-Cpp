#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_set>

using namespace std;

#include "Lista.h"

int main() {
    srand(time(nullptr));
    int N = 10; // Número de listas
    int M = 5; // Tamanho das listas

    vector<vector<int>> listas(N);
    for (int i = 0; i < N; ++i) {
        listas[i] = gerarListaAleatoria(M);
    }

    mostrarConteudos(listas);
    mostrarNumerosNasListas(listas);
    mostrarNumerosUmaLista(listas);

    return 0;
}
