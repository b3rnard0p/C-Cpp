#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

// Enum para representar o tipo de funcionário
enum TipoFuncionario {
    PROFESSOR,
    COORDENADOR
};

// Struct para representar um funcionário
struct Funcionario {
    string nome;
    int numero;
    TipoFuncionario tipo;
};

struct PermissaoAluno {
    int numero;
    bool permissao;
};

// Struct para representar um aluno
struct Aluno {
    string nome;
    int numero;
};

// Struct para representar uma sala de aula
struct SalaAula {
    string nome;
    string predio;
    bool chavePega; 
};



// Função para cadastrar um novo funcionário
void cadastrarFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario novoFuncionario;
    cout << "Digite o nome do funcionário: ";
    cin >> novoFuncionario.nome;
    cout << "Digite o numero do funcionário: ";
    cin >> novoFuncionario.numero;

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

    funcionarios.push_back(novoFuncionario);
    cout << "Funcionário cadastrado com sucesso!\n";

    // Salvando dados em um arquivo CSV
    ofstream arquivo("funcionarios.csv", ios::app);  // Abre o arquivo em modo de adição

    if (arquivo.is_open()) {
        arquivo << novoFuncionario.nome << "," << novoFuncionario.numero << ",";
        if (novoFuncionario.tipo == PROFESSOR) {
            arquivo << "Professor";
        } else {
            arquivo << "Coordenador";
        }
        arquivo << "\n";
        arquivo.close();
        cout << "Dados do funcionário salvo em funcionarios.csv.\n";
    } else {
        cout << "Erro ao abrir o arquivo funcionarios.csv para escrita.\n";
    }
}

// Função para listar todos os funcionários
void listarFuncionarios(const vector<Funcionario>& funcionarios) {
    if (funcionarios.empty()) {
        cout << "Nenhum funcionário cadastrado.\n";
    } else {
        cout << "Lista de Funcionários:\n";
        for (const Funcionario& funcionario : funcionarios) {
            cout << "Nome: " << funcionario.nome << ", Matrícula: " << funcionario.numero;
            if (funcionario.tipo == PROFESSOR) {
                cout << ", Tipo: Professor";
            } else {
                cout << ", Tipo: Coordenador";
            }
            cout << "\n";
        }
    }
}

// Função para cadastrar um novo aluno
void cadastrarAluno(vector<Aluno>& alunos) {
    Aluno novoAluno;
    cout << "Digite o nome do aluno: ";
    cin >> novoAluno.nome;
    cout << "Digite o numero do aluno: ";
    cin >> novoAluno.numero;
    alunos.push_back(novoAluno);
    cout << "Aluno cadastrado com sucesso!\n";

    // Salvando dados em um arquivo CSV
    ofstream arquivo("alunos.csv", ios::app);  // Abre o arquivo em modo de adição

    if (arquivo.is_open()) {
        arquivo << novoAluno.nome << "," << novoAluno.numero << "\n";
        arquivo.close();
        cout << "Dados do aluno salvo em alunos.csv.\n";
    } else {
        cout << "Erro ao abrir o arquivo alunos.csv para escrita.\n";
    }
}

// Função para listar todos os alunos
void listarAlunos(const vector<Aluno>& alunos) {
    if (alunos.empty()) {
        cout << "Nenhum aluno cadastrado.\n";
    } else {
        cout << "Lista de Alunos:\n";
        for (const Aluno& aluno : alunos) {
            cout << "Nome: " << aluno.nome << ", Matrícula: " << aluno.numero << "\n";
        }
    }
}

// Função para cadastrar uma nova sala de aula
void cadastrarSala(vector<SalaAula>& salas) {
    SalaAula novaSala;
    cout << "Digite o nome da sala: ";
    cin >> novaSala.nome;
    cout << "Digite o nome do prédio: ";
    cin >> novaSala.predio;
    novaSala.chavePega = false;  // Inicializa com chave não pega
    salas.push_back(novaSala);
    cout << "Sala cadastrada com sucesso!\n";

    // Salvando dados em um arquivo CSV
    ofstream arquivo("salas.csv", ios::app);  // Abre o arquivo em modo de adição

    if (arquivo.is_open()) {
        arquivo << novaSala.nome << "," << novaSala.predio << "," << novaSala.chavePega << "\n";
        arquivo.close();
        cout << "Dados da sala salvo em salas.csv.\n";
    } else {
        cout << "Erro ao abrir o arquivo salas.csv para escrita.\n";
    }
}

// Modifique a função listarSalas da seguinte maneira:
void listarSalas(const vector<SalaAula>& salas) {
    if (salas.empty()) {
        cout << "Nenhuma sala cadastrada.\n";
    } else {
        cout << "Lista de Salas:\n";
        for (size_t i = 0; i < salas.size(); ++i) {
            cout << i + 1 << " - Sala: " << salas[i].nome << ", Prédio: " << salas[i].predio;
            cout << "\n";
        }
    }
}

// Adicione esta função para salvar informações sobre quem pegou a chave em um arquivo CSV
void salvarRegistroChave(const string& nomeFuncionario, const string& nomeSala, const string& predio) {
    ofstream arquivo("registro_chaves.csv", ios::app);
    if (arquivo.is_open()) {
        arquivo << nomeFuncionario << "," << nomeSala << "," << predio << "\n";
        arquivo.close();
        cout << "Registro salvo em registro_chaves.csv.\n";
    } else {
        cout << "Erro ao abrir o arquivo registro_chaves.csv para escrita.\n";
    }
}



bool verificarPermissaoAluno(const vector<PermissaoAluno>& permissoes, int numeroAluno) {
    for (const PermissaoAluno& permissao : permissoes) {
        if (permissao.numero == numeroAluno) {
            return permissao.permissao;
        }
    }
    return false; // Se não encontrar, assume que não tem permissão
}

// Modifique a função pegarChaveSala da seguinte maneira:
void pegarChaveSala(const vector<PermissaoAluno>& permissoes, const vector<Funcionario>& funcionarios, vector<SalaAula>& salas, const vector<Aluno>& alunos) {
    if (salas.empty()) {
        cout << "Nenhuma sala cadastrada.\n";
        return;
    }

    cout << "Você é um aluno com permissão (digite 'A') ou um funcionário (digite 'F')? ";
    char opcaoUsuario;
    cin >> opcaoUsuario;

    if (opcaoUsuario == 'A' || opcaoUsuario == 'a') {
        // Usuário é um aluno
        cout << "Escolha a sala para pegar a chave:\n";

        for (size_t i = 0; i < salas.size(); ++i) {
            cout << i + 1 << " - Sala: " << salas[i].nome << ", Prédio: " << salas[i].predio;
            if (salas[i].chavePega) {
                cout << " (Chave já foi pega)";
            }
            cout << "\n";
        }

        size_t escolhaSala;
        cin >> escolhaSala;

        if (escolhaSala > 0 && escolhaSala <= salas.size()) {
            // Verifica se a chave já foi pega
            if (salas[escolhaSala - 1].chavePega) {
                cout << "A chave da sala " << salas[escolhaSala - 1].nome << " já foi pega anteriormente.\n";
                return;
            }

            // Marca a chave como pega
            salas[escolhaSala - 1].chavePega = true;

            // Registra quem pegou a chave e de qual sala no arquivo CSV
            salvarRegistroChave(alunos[escolhaSala - 1].nome, salas[escolhaSala - 1].nome, salas[escolhaSala - 1].predio);
            cout << "Aluno com permissão pegou a chave da sala: " << salas[escolhaSala - 1].nome << "\n";
        } else {
            cout << "Escolha de sala inválida.\n";
        }
    } else if (opcaoUsuario == 'F' || opcaoUsuario == 'f') {
        // Usuário é um funcionário
        cout << "Escolha a sala para pegar a chave:\n";

        for (size_t i = 0; i < salas.size(); ++i) {
            cout << i + 1 << " - Sala: " << salas[i].nome << ", Prédio: " << salas[i].predio;
            if (salas[i].chavePega) {
                cout << " (Chave já foi pega)";
            }
            cout << "\n";
        }

        size_t escolhaSala;
        cin >> escolhaSala;

        if (escolhaSala > 0 && escolhaSala <= salas.size()) {
            // Verifica se a chave já foi pega
            if (salas[escolhaSala - 1].chavePega) {
                cout << "A chave da sala " << salas[escolhaSala - 1].nome << " já foi pega anteriormente.\n";
                return;
            }

            // Marca a chave como pega
            salas[escolhaSala - 1].chavePega = true;

            // Registra quem pegou a chave e de qual sala no arquivo CSV
            salvarRegistroChave(funcionarios[escolhaSala - 1].nome, salas[escolhaSala - 1].nome, salas[escolhaSala - 1].predio);
            cout << "Funcionário pegou a chave da sala: " << salas[escolhaSala - 1].nome << "\n";
        } else {
            cout << "Escolha de sala inválida.\n";
        }
    } else {
        cout << "Opção inválida.\n";
    }
}


// Função para ler registros de chaves de um arquivo CSV
void lerRegistrosChaves() {
    ifstream arquivo("registro_chaves.csv");
    if (arquivo.is_open()) {
        cout << "\nRegistros de Chaves:\n";
        cout << "---------------------\n";

        while (arquivo) {
            string nomeFuncionario, nomeSala, predio;

            // Leia até a próxima vírgula ou final de linha
            getline(arquivo, nomeFuncionario, ',');

            // Se o nomeFuncionario estiver vazio, chegamos ao final do arquivo
            if (nomeFuncionario.empty()) {
                break;
            }

            getline(arquivo, nomeSala, ',');
            getline(arquivo, predio, '\n');

            cout << "Funcionário: " << nomeFuncionario << ", Sala: " << nomeSala << ", Prédio: " << predio << "\n";
        }

        cout << "---------------------\n";
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo registro_chaves.csv para leitura.\n";
    }
}



// Função para ler funcionários de um arquivo CSV
void lerFuncionarios(vector<Funcionario>& funcionarios) {
    ifstream arquivo("funcionarios.csv");
    if (arquivo.is_open()) {
        while (!arquivo.eof()) {
            Funcionario novoFuncionario;
            char tipo;
            arquivo >> novoFuncionario.nome >> novoFuncionario.numero >> tipo;
            if (tipo == 'P') {
                novoFuncionario.tipo = PROFESSOR;
            } else {
                novoFuncionario.tipo = COORDENADOR;
            }
            funcionarios.push_back(novoFuncionario);
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo funcionarios.csv para leitura.\n";
    }
}

// Função para ler alunos de um arquivo CSV
void lerAlunos(vector<Aluno>& alunos) {
    ifstream arquivo("alunos.csv");
    if (arquivo.is_open()) {
        while (!arquivo.eof()) {
            Aluno novoAluno;
            arquivo >> novoAluno.nome >> novoAluno.numero;
            alunos.push_back(novoAluno);
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo alunos.csv para leitura.\n";
    }
}

// Função para ler salas de aula de um arquivo CSV
void lerSalas(vector<SalaAula>& salas) {
    ifstream arquivo("salas.csv");
    if (arquivo.is_open()) {
        while (!arquivo.eof()) {
            SalaAula novaSala;
            char chavePega;
            arquivo >> novaSala.nome >> novaSala.predio >> chavePega;
            novaSala.chavePega = (chavePega == '1');
            salas.push_back(novaSala);
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo salas.csv para leitura.\n";
    }
}


// Função para listar alunos com permissão de um arquivo CSV
void listarAlunosPermitidos(const vector<Aluno>& alunos, const vector<PermissaoAluno>& permissoes) {
    cout << "Lista de Alunos com Permissão:\n";
    for (const PermissaoAluno& permissao : permissoes) {
        auto alunoIt = find_if(alunos.begin(), alunos.end(), [permissao](const Aluno& aluno) {
            return aluno.numero == permissao.numero;
        });

        if (alunoIt != alunos.end()) {
            cout << "Número: " << alunoIt->numero << ", Nome: " << alunoIt->nome << "\n";
        }
    }
}
// Modifique a função darPermissaoAluno da seguinte maneira:
void darPermissaoAluno(vector<PermissaoAluno>& permissoes, const vector<Aluno>& alunos) {
    if (alunos.empty()) {
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    cout << "Escolha o número do aluno para dar permissão:\n";
    for (const Aluno& aluno : alunos) {
        cout << "Número: " << aluno.numero << ", Nome: " << aluno.nome << "\n";
    }

    int escolhaAluno;
    cin >> escolhaAluno;

    // Verifica se o aluno escolhido existe
    auto it = find_if(alunos.begin(), alunos.end(), [escolhaAluno](const Aluno& aluno) {
        return aluno.numero == escolhaAluno;
    });

    if (it != alunos.end()) {
        // Verifica se o aluno já tem uma entrada de permissão
        auto permissaoIt = find_if(permissoes.begin(), permissoes.end(), [escolhaAluno](const PermissaoAluno& permissao) {
            return permissao.numero == escolhaAluno;
        });

        if (permissaoIt != permissoes.end()) {
            cout << "O aluno já possui permissão.\n";
        } else {
            // Adiciona uma nova entrada para o aluno
            PermissaoAluno novaPermissao;
            novaPermissao.numero = escolhaAluno;
            novaPermissao.permissao = true;
            permissoes.push_back(novaPermissao);
            cout << "Permissão concedida ao aluno.\n";

            // Salva a nova permissão no arquivo CSV
            ofstream arquivo("permissoes.csv", ios::app);
            if (arquivo.is_open()) {
                arquivo << novaPermissao.numero << "," << novaPermissao.permissao << "\n";
                arquivo.close();
                cout << "Permissão salva em permissoes.csv.\n";
            } else {
                cout << "Erro ao abrir o arquivo permissoes.csv para escrita.\n";
            }
        }
    } else {
        cout << "Aluno não encontrado.\n";
    }
}

// Função para ler permissões de um arquivo CSV
void lerPermissoes(vector<PermissaoAluno>& permissoes) {
    ifstream arquivo("permissoes.csv");
    if (arquivo.is_open()) {
        while (!arquivo.eof()) {
            PermissaoAluno permissao;
            arquivo >> permissao.numero >> permissao.permissao;
            permissoes.push_back(permissao);
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo permissoes.csv para leitura.\n";
    }
}

// Função para salvar permissões em um arquivo CSV
void salvarPermissoes(const vector<PermissaoAluno>& permissoes) {
    ofstream arquivo("permissoes.csv");
    if (arquivo.is_open()) {
        for (const PermissaoAluno& permissao : permissoes) {
            arquivo << permissao.numero << "," << permissao.permissao << "\n";
        }
        arquivo.close();
        cout << "Permissões salvas em permissoes.csv.\n";
    } else {
        cout << "Erro ao abrir o arquivo permissoes.csv para escrita.\n";
    }
}




int main() {
    vector<Funcionario> funcionarios;
    vector<Aluno> alunos;
    vector<SalaAula> salas;
    vector<PermissaoAluno> permissoes;

     // Lê dados dos arquivos CSV
    lerFuncionarios(funcionarios);
    lerAlunos(alunos);
    lerSalas(salas);
    lerPermissoes(permissoes);

    while (true) {
        cout << "\nMenu Principal:\n";
        cout << "1 - Cadastrar Funcionário\n";
        cout << "2 - Cadastrar Aluno\n";
        cout << "3 - Cadastrar Sala\n";
        cout << "4 - Listar\n";
        cout << "5 - Pegar Chave de Sala\n";
        cout << "6 - Dar Permissão a Aluno\n";  // Corrigindo o número da opção
        cout << "7 - Sair\n";
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarFuncionario(funcionarios);
                break;
            case 2:
                cadastrarAluno(alunos);
                break;
            case 3:
                cadastrarSala(salas);
                break;
            case 4: {
                cout << "\nMenu Listar:\n";
                cout << "1 - Listar Funcionários\n";
                cout << "2 - Listar Alunos\n";
                cout << "3 - Listar Salas\n";
                cout << "4 - Listar chaves pegas\n";
                cout << "Escolha uma opção: ";

                int opcaoListar;
                cin >> opcaoListar;

                switch (opcaoListar) {
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
                        lerRegistrosChaves();
                        break;
                    default:
                        cout << "Opção inválida. Tente novamente.\n";
                }
                break;
            }
            case 5:
              pegarChaveSala(permissoes, funcionarios, salas, alunos);
                break;
            case 6:
               darPermissaoAluno(permissoes, alunos);
                break;
            case 7:
                cout << "Saindo do programa.\n";
                return 0;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    }

    return 0;
}
