#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct para representar uma sala de aula
struct SalaAula {
    string nome;
    string predio;
};

// Função para registrar uma nova sala de aula
void registrarSala(vector<SalaAula>& salas) {
    SalaAula novaSala;
    cout << "Digite o nome da sala: ";
    cin >> novaSala.nome;
    cout << "Digite o nome do prédio: ";
    cin >> novaSala.predio;
    salas.push_back(novaSala);  // Adiciona a sala atual ao vetor
    cout << "Sala registrada com sucesso!\n";
}

// Função para exibir detalhes da sala
void exibirDetalhes(const SalaAula& sala) {
    cout << "Sala: " << sala.nome << ", Prédio: " << sala.predio << "\n";
}

// Função para listar todas as salas
void listarSalas(const vector<SalaAula>& salas) {
    if (salas.empty()) {
        cout << "Nenhuma sala registrada.\n";
    } else {
        cout << "Lista de Salas:\n";
        for (const SalaAula& sala : salas) {
            exibirDetalhes(sala);
        }
    }
}

int main() {
    vector<SalaAula> salas;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1 - Registrar Nova Sala\n";
        cout << "2 - Listar Salas\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";

        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1:
                registrarSala(salas);
                break;
            case 2:
                listarSalas(salas);
                break;
            case 3:
                cout << "Saindo do programa.\n";
                return 0;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    }

    return 0;
}
