#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

#include "Struct.h"
#include "Funcionarios.h"
#include "Salas.h"
#include "Chaves.h"
#include "Permissoes.h"
#include "Alunos.h"

int main()
{
    vector<Funcionario> funcionarios;
    vector<Aluno> alunos;
    vector<SalaAula> salas;
    vector<PermissaoAluno> permissoes;
    vector<string> chavesPegas;


    lerFuncionarios(funcionarios);
    lerAlunos(alunos);
    lerSalas(salas);
    lerPermissoes(permissoes);

    while (true)
    {
        cout << "\nMenu Principal:\n";
        cout << "1 - Cadastrar Funcionário\n";
        cout << "2 - Cadastrar Aluno\n";
        cout << "3 - Cadastrar Sala\n";
        cout << "4 - Listar\n";
        cout << "5 - Pegar Chave de Sala\n";
        cout << "6 - Dar Permissão a Aluno\n";
        cout << "7 - Remover\n";
        cout << "8 - Devolver chave\n";
        cout << "9- Sair\n";
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastrarFuncionario(funcionarios);
            break;
        case 2:
            cadastrarAluno(alunos);
            break;
        case 3:
            cadastrarSala(salas);
            break;
        case 4:
        {
            cout << "\nMenu Listar:\n";
            cout << "1 - Listar Funcionários\n";
            cout << "2 - Listar Alunos\n";
            cout << "3 - Listar Salas\n";
            cout << "4 - Listar Chaves Pegas\n";
            cout << "5 - Listar Alunos Permitidos\n";
            cout << "Escolha uma opção: ";

            int opcaoListar;
            cin >> opcaoListar;

            switch (opcaoListar)
            {
            case 1:
                listarFuncionarios(funcionarios);
                break;
            case 2:
                listarAlunos(alunos);
                break;
            case 3:
                listarSalas(salas);
                break;
            case 4:
                listarChavesPegas(funcionarios, alunos);
                break;
            case 5:
                listarAlunosPermitidos(alunos, permissoes);
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
            }
            break;
        }
        case 5:
            pegarChaveSala(permissoes, funcionarios, salas, alunos, chavesPegas);
            break;
        case 6:
            darPermissaoAluno(permissoes, alunos);
            break;
        case 7:
            cout << "\nMenu Remover:\n";
            cout << "1 - Remover Funcionário\n";
            cout << "2 - Remover Aluno\n";
            cout << "3 - Remover Sala\n";
            cout << "4 - Remover Permissão de Aluno\n";
            cout << "Escolha uma opção: ";

            int opcaoRemover;
            cin >> opcaoRemover;

            switch (opcaoRemover)
            {
            case 1:
                removerFuncionario(funcionarios);
                break;
            case 2:
                removerAluno(alunos);
                break;
            case 3:
                removerSala(salas);
                break;
            case 4:
                removerPermissaoAluno(permissoes);
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
            }
            break;
            case 8:
        devolverChave(salas, chavesPegas);
        break;
        case 9:
            cout << "Saindo do programa.\n";
            return 0;
        default:
            cout << "Opção inválida. Tente novamente.\n";
        }
    }

    return 0;
}