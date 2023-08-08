#include <iostream>
#include <string>
#include <stdio.h>
#define TAM 5

using namespace std;

int main() {
    string vetor[TAM];
    int i=0,j=0;

    for (i = 0; i < TAM; i++) {
        cout << "Digite um nome:";
        getline(cin, vetor[i]);
        fflush(stdin);
        for (j = 0; j < i; j++) {
            if (vetor[j] == vetor[i]) {
                cout << "Nome repetido." << endl;
                i--;
                break;
            }
        }
    }

    for (i = 0; i < TAM - 1; i++) {
        for (j = 0; j < TAM - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                string temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
    
    for (i = 0; i < TAM; i++) {
        cout << vetor[i] << endl;
    }

    return 0;
}

