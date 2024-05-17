#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

using namespace std;

#include "Struct.h"
#include "Metodos.h"

int main() {
    vector<Amigo> listaAmigos;
    vector<Amigo> listaAmigosEmbaralhada;

    carregarAmigos(listaAmigos, "amigos.csv");

    int opcao;
    string nome, email;

    while (true) {
        cout << "Menu:\n";
        cout << "1 - Cadastrar amigo\n";
        cout << "2 - Listar amigos (amigos.csv)\n";
        cout << "3 - Gerar Amigo Secreto (amigosecreto.csv)\n";
        cout << "4 - Sair\n";
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                cout << "Digite o nome do amigo: ";
                cin.ignore();
                getline(cin, nome);

                cout << "Digite o email do amigo: ";
                cin >> email;

                Amigo novoAmigo = {nome, email};
                listaAmigos.push_back(novoAmigo);
                salvarAmigos(listaAmigos, "amigos.csv");
                break;
            }
            case 2: {
                cout << "Amigos cadastrados:\n";
                for (const Amigo& amigo : listaAmigos) {
                    cout << "Nome: " << amigo.nome << ", Email: " << amigo.email << endl;
                }
                break;
            }
            case 3: {
                if (listaAmigos.empty()) {
                    cout << "Não há amigos cadastrados para realizar o sorteio." << endl;
                    continue;
                }

                listaAmigosEmbaralhada = embaralharAmigosAteNinguemPegarSiMesmo(listaAmigos);
                criarArquivoAmigoSecreto(listaAmigos, listaAmigosEmbaralhada, "amigosecreto.csv");
                break;
            }
            case 4: {
                salvarAmigos(listaAmigos, "amigos.csv");
                return 0;
            }
            default: {
                cout << "Opção inválida. Tente novamente.\n";
                break;
            }
        }
    }

    return 0;
}
