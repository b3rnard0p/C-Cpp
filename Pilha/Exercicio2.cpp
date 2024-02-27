#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef struct nodo {
    int valor;
    struct nodo *prox;
} Pilha;

Pilha *inserir(int valor, Pilha *topo) {
    Pilha *novo = new Pilha;
    novo->valor = valor;
    novo->prox = topo;
    return novo;
}

int main() {
    // Gerar números aleatórios e escrevê-los em um arquivo
    ofstream outFile("numeros.txt");
    if (!outFile) {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
        return 1;
    }

    int n;
    cout << "Quantos numeros aleatorios deseja gerar e escrever no arquivo? ";
    cin >> n;

    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        int valor = rand() % 100; // Gerar número aleatório entre 0 e 99
        outFile << valor << endl;
    }
    outFile.close();
    cout << "Numeros aleatorios gerados e escritos no arquivo." << endl;

    // Ler os números do arquivo e inseri-los na pilha
    Pilha *pilha = nullptr;
    ifstream inFile("numeros.txt");
    if (!inFile) {
        cerr << "Erro ao abrir o arquivo para leitura." << endl;
        return 1;
    }

    int numero;
    while (inFile >> numero) {
        pilha = inserir(numero, pilha);
    }
    inFile.close();

    // Mostrar o elemento no topo da pilha e o tamanho da pilha
    if (pilha) {
        cout << "Elemento no topo da pilha: " << pilha->valor << endl;
        int tamanhoPilha = 0;
        for (Pilha *temp = pilha; temp != nullptr; temp = temp->prox) {
            tamanhoPilha++;
        }
        cout << "Tamanho da pilha: " << tamanhoPilha << endl;
    } else {
        cout << "A pilha esta vazia." << endl;
    }

    return 0;
}
