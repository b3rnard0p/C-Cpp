#include <iostream>
#include <ctime>
#include <cstdlib>

#define TAM 10

using namespace std;

typedef struct {
    int x;
    int y;
} Ponto;

int main() {
    int i;
    Ponto vetor[TAM];
    srand(time(NULL));

    for (i = 0; i < TAM; i++) {
        vetor[i].x = rand() % 13 - 6;
        vetor[i].y = rand() % 13 - 6;
    }

    for (i = 0; i < TAM; i++) {
        cout << "Ponto " << i + 1 << " - Coordenadas: (" << vetor[i].x << ", " << vetor[i].y << ") - Quadrante: ";

        if (vetor[i].x > 0 && vetor[i].y > 0) {
            cout << "Quadrante 1";
        } else if (vetor[i].x < 0 && vetor[i].y > 0) {
            cout << "Quadrante 2";
        } else if (vetor[i].x < 0 && vetor[i].y < 0) {
            cout << "Quadrante 3";
        } else if (vetor[i].x > 0 && vetor[i].y < 0) {
            cout << "Quadrante 4";
        } else {
            cout << "Eixo";
        }
        cout << endl;
    }

    return 0;
}
