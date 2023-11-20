#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Enum para representar o tipo de funcionário
enum TipoFuncionario {
    PROFESSOR,
    COORDENADOR
};

// Struct para representar um funcionário
struct Funcionario {
    string nome;
    int matricula;
    TipoFuncionario tipo;
};

// Função para registrar um novo funcionário
void registrarFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario novoFuncionario;
    cout << "Digite o nome do funcionário: ";
    cin >> novoFuncionario.nome;
    cout << "Digite a matrícula do funcionário: ";
    cin >> novoFuncionario.matricula;

    cout << "Escolha o tipo de funcionário:\n";
    cout << "1 - Professor\n";
    cout << "2 - Coordenador\n";
    int opcaoTipo;
    cin >> opcaoTipo;

    switch (opcaoTipo) {
        case 1:
            novoFuncionario.tipo = PROFESSOR;
            break;
        case 2:
            novoFuncionario.tipo = COORDENADOR;
            break;
        default:
            cout << "Opção inválida. Definindo como Professor por padrão.\n";
            novoFuncionario.tipo = PROFESSOR;
    }

    funcionarios.push_back(novoFuncionario);  // Adiciona o funcionário atual ao vetor
    cout << "Funcionário registrado com sucesso!\n";
}

// Função para exibir detalhes do funcionário
void exibirDetalhes(const Funcionario& funcionario) {
    string tipo;
    if (funcionario.tipo == PROFESSOR) {
        tipo = "Professor";
    } else {
        tipo = "Coordenador";
    }
    cout << "Nome: " << funcionario.nome << ", Matrícula: " << funcionario.matricula << ", Tipo: " << tipo << "\n";
}

// Função para listar todos os funcionários
void listarFuncionarios(const vector<Funcionario>& funcionarios) {
    if (funcionarios.empty()) {
        cout << "Nenhum funcionário registrado.\n";
    } else {
        cout << "Lista de Funcionários:\n";
        for (const Funcionario& funcionario : funcionarios) {
            exibirDetalhes(funcionario);
        }
    }
}

int main() {
    vector<Funcionario> funcionarios;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1 - Registrar Novo Funcionário\n";
        cout << "2 - Listar Funcionários\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";

        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1:
                registrarFuncionario(funcionarios);
                break;
            case 2:
                listarFuncionarios(funcionarios);
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
