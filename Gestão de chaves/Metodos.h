// Função para cadastrar um novo funcionário
void cadastrarFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario novoFuncionario;
    cout << "Digite o nome do funcionário: ";
    cin >> novoFuncionario.nome;
    cout << "Digite o número do funcionário: ";
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
    salas.push_back(novaSala);
    cout << "Sala cadastrada com sucesso!\n";

     // Salvando dados em um arquivo CSV
    ofstream arquivo("salas.csv", ios::app);  // Abre o arquivo em modo de adição

    if (arquivo.is_open()) {
        arquivo << novaSala.nome << "," << novaSala.predio << "\n";
        arquivo.close();
        cout << "Dados da sala salvo em salas.csv.\n";
    } else {
        cout << "Erro ao abrir o arquivo salas.csv para escrita.\n";
    }
}

// Função para listar todas as salas de aula
void listarSalas(const vector<SalaAula>& salas) {
    if (salas.empty()) {
        cout << "Nenhuma sala cadastrada.\n";
    } else {
        cout << "Lista de Salas:\n";
        for (const SalaAula& sala : salas) {
            cout << "Sala: " << sala.nome << ", Prédio: " << sala.predio << "\n";
        }
    }
}

void pegarChaveSala(const vector<Funcionario>& funcionarios, vector<SalaAula>& salas) {
    if (salas.empty()) {
        cout << "Nenhuma sala cadastrada.\n";
        return;
    }

    cout << "Escolha o número da sala para pegar a chave:\n";
    for (int i = 0; i < salas.size(); ++i) {
        cout << i + 1 << " - Sala: " << salas[i].nome << ", Prédio: " << salas[i].predio;
        if (salas[i].chavePega) {
            cout << " (Chave Pega)";
        }
        cout << "\n";
    }

    int escolhaSala;
    cin >> escolhaSala;

    if (escolhaSala > 0 && escolhaSala <= salas.size()) {
        // Verifica se a chave já foi pega
        if (salas[escolhaSala - 1].chavePega) {
            cout << "A chave da sala " << salas[escolhaSala - 1].nome << " já foi pega anteriormente.\n";
            return;
        }

        cout << "Escolha o seu número de funcionário para se identificar:\n";
        for (int i = 0; i < funcionarios.size(); ++i) {
            cout << i + 1 << " - " << funcionarios[i].nome << "\n";
        }

        int escolhaFuncionario;
        cin >> escolhaFuncionario;

        if (escolhaFuncionario > 0 && escolhaFuncionario <= funcionarios.size()) {
            // Verifica se o funcionário é professor
            if (funcionarios[escolhaFuncionario - 1].tipo == PROFESSOR) {
                // Marca a chave como pega
                salas[escolhaSala - 1].chavePega = true;

                // Registra quem pegou a chave e de qual sala no arquivo CSV
                ofstream arquivo("registro_chaves.csv", ios::app);
                if (arquivo.is_open()) {
                    arquivo << funcionarios[escolhaFuncionario - 1].nome << ","
                            << salas[escolhaSala - 1].nome << ","
                            << salas[escolhaSala - 1].predio << "\n";
                    arquivo.close();
                    cout << "Registro salvo em registro_chaves.csv.\n";
                } else {
                    cout << "Erro ao abrir o arquivo registro_chaves.csv para escrita.\n";
                }

                cout << "Você, como professor, pegou a chave da sala: " << salas[escolhaSala - 1].nome << "\n";
            } else {
                cout << "Apenas professores podem pegar chaves.\n";
            }
        } else {
            cout << "Escolha de funcionário inválida.\n";
        }
    } else {
        cout << "Escolha de sala inválida.\n";
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
