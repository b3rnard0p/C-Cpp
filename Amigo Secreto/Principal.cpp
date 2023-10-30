#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

using namespace std;

struct Amigo {
    string nome;
    string email;
};

void salvarAmigos(const vector<Amigo>& amigos, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        for (const Amigo& amigo : amigos) {
            arquivo << amigo.nome << "," << amigo.email << "\n";
        }
        arquivo.close();
    } else {
        cout << "Erro ao criar o arquivo: " << nomeArquivo << endl;
    }
}

void carregarAmigos(vector<Amigo>& amigos, const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        amigos.clear();
        string linha;
        while (getline(arquivo, linha)) {
            size_t pos = linha.find(",");
            if (pos != string::npos) {
                Amigo novoAmigo;
                novoAmigo.nome = linha.substr(0, pos);
                novoAmigo.email = linha.substr(pos + 1);
                amigos.push_back(novoAmigo);
            }
        }
        arquivo.close();
    }
}

vector<Amigo> embaralharAmigos(const vector<Amigo>& amigos) {
    vector<Amigo> amigosEmbaralhados = amigos;
    random_device rd;
    mt19937 g(rd());
    shuffle(amigosEmbaralhados.begin(), amigosEmbaralhados.end(), g);
    return amigosEmbaralhados;
}

void verificacao(const vector<Amigo>& amigos, const vector<Amigo>& amigosEmbaralhados){
    for(size_t i = 0; i < amigos.size(); ++i){
    if(amigos[i].nome == amigosEmbaralhados[i].nome){
       embaralharAmigos(amigos, amigosEmbaralhados);
    }
    else{
        return;
    }
    }

}
void criarArquivoAmigoSecreto(const vector<Amigo>& listaAmigos, const vector<Amigo>& listaAmigosEmbaralhada, const string& nomeArquivo) {
    ofstream arquivoAmigoSecreto(nomeArquivo);

    if (arquivoAmigoSecreto.is_open()) {
        for (size_t i = 0; i < listaAmigos.size(); ++i) {
            arquivoAmigoSecreto << listaAmigos[i].nome << " tira " << listaAmigosEmbaralhada[i].nome << endl;
        }
        arquivoAmigoSecreto.close();
        cout << "Sorteio de Amigo Secreto concluído. Resultados no arquivo " << nomeArquivo << ".\n";
    } else {
        cout << "Erro ao criar o arquivo de Amigo Secreto.\n";
    }
}

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

                listaAmigosEmbaralhada = embaralharAmigos(listaAmigos);
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
