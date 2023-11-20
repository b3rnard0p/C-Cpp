#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct para representar um aluno
struct Aluno {
    string nome;
    int matricula;
};

// Função para registrar um novo aluno
void registrarAluno(vector<Aluno>& alunos) {
    Aluno novoAluno;
    cout << "Digite o nome do aluno: ";
    cin >> novoAluno.nome;
    cout << "Digite a matrícula do aluno: ";
    cin >> novoAluno.matricula;
    alunos.push_back(novoAluno);  // Adiciona o aluno atual ao vetor
    cout << "Aluno registrado com sucesso!\n";
}

// Função para exibir detalhes do aluno
void exibirDetalhes(const Aluno& aluno) {
    cout << "Nome: " << aluno.nome << ", Matrícula: " << aluno.matricula << "\n";
}

// Função para listar todos os alunos
void listarAlunos(const vector<Aluno>& alunos) {
    if (alunos.empty()) {
        cout << "Nenhum aluno registrado.\n";
    } else {
        cout << "Lista de Alunos:\n";
        for (const Aluno& aluno : alunos) {
            exibirDetalhes(aluno);
        }
    }
}

int main() {
    vector<Aluno> alunos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1 - Registrar Novo Aluno\n";
        cout << "2 - Listar Alunos\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";

        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1:
                registrarAluno(alunos);
                break;
            case 2:
                listarAlunos(alunos);
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
