#include <iostream>
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

void imprimir(Pilha *topo) {
    if (!topo) return;
    for (Pilha *i = topo; i != NULL; i = i->prox) {
        cout << i->valor << endl;
    }
}

int contarElementos(Pilha *topo) {
    if (!topo) return 0;
    int quantidade = 0;
    for (Pilha *i = topo; i != NULL; i = i->prox) {
        quantidade++;
    }
    return quantidade;
}

bool estaContido(int valor, Pilha *topo) {
    if (!topo) return false;
    for (Pilha *i = topo; i != NULL; i = i->prox) {
        if (valor == i->valor){
            return true;
        }
    }
    return false;
}

Pilha *remover(Pilha *topo) {
    if (!topo) return topo;
    Pilha *lixo = topo;
    topo = topo->prox;
    delete lixo;
    return topo;
}

int main() {
    Pilha *pilha = NULL;

    int quantidadeNumeros;
    cout << "Quantos numeros quer armazenar na pilha? ";
    cin >> quantidadeNumeros;

    srand(time(NULL));
    while (quantidadeNumeros > 0) {
        int valor = rand() % 100;

        // Verificar se o número já está presente na pilha
        if (!estaContido(valor, pilha)) {
            
            // Se o número gerado for par, inseri-lo na pilha
            if (valor % 2 == 0) { 
                pilha = inserir(valor, pilha);
                cout << "Numero par inserido na pilha: " << valor << endl;
                quantidadeNumeros--; // Reduzir a quantidade de números restantes apenas se um número único for inserido
            } 
            // Se o número gerado for ímpar, substituir o número par no topo da pilha, se possível
            else { 
                if (!pilha) {
                    cout << "Pilha vazia, não é possível substituir um par." << endl;
                } else {
                    cout << "Substituindo um par do topo da pilha por: " << valor << endl;
                    pilha->valor = valor;
                }
            }
        }
    }

    cout << "Conteudo final da pilha:" << endl;
    imprimir(pilha);
    cout << "Pilha com um total de " << contarElementos(pilha) << " elementos" << endl;

    return 0;
}
