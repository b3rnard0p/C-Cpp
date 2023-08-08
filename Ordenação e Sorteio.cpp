#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdbool.h>
#define TAM 5

using namespace std;

int main() {
    int vetor[TAM];
    int i;

    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % 50;
         cout << vetor[i]<<" ";
    }
    cout << "\n\n";

    bool houveTroca;
    int tmp;
    do {
        houveTroca = false;
        for (int i = 0; i < TAM - 1; i++) {
            if (vetor[i] > vetor[i + 1]) {
                houveTroca = true;
                tmp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = tmp;
            }
        }

    } while (houveTroca);
    
    for (int i = 0; i < TAM; i++) {
        cout << vetor[i] << endl;
    }
    
    return 0;
}


