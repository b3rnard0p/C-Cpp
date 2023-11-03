#include <iostream>
#include <vector>
using namespace std;

vector<int> inicializarVetorZeros(int tamanho) {
    vector<int> vetor(tamanho, 0);
    return vetor;
}

int main() {
    int tamanho;

    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    vector<int> vetorZeros = inicializarVetorZeros(tamanho);

    cout << "Vetor inicializado com zeros: ";
    for (int valor : vetorZeros) {
        cout << valor << " ";
    }
    cout << endl;

    return 0;
}
