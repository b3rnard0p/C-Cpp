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

    ofstream arquivo("funcionarios.csv", ios::app); 

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

void listarFuncionarios(const vector<Funcionario> &funcionarios)
{
    cout << "Lista de Funcionários:\n";
    for (const Funcionario &funcionario : funcionarios)
    {
        cout << "Nome: " << funcionario.nome << ", Numero: " << funcionario.numero;
        if (funcionario.tipo == PROFESSOR)
        {
            cout << ", Tipo: Professor";
        }
        else
        {
            cout << ", Tipo: Coordenador";
        }
        cout << "\n";
    }
}

void lerFuncionarios(vector<Funcionario>& funcionarios) {
    ifstream arquivoFuncionarios("funcionarios.csv");
    if (arquivoFuncionarios.is_open()) {
        while (!arquivoFuncionarios.eof()) {
            Funcionario novoFuncionario;
            char tipo;
            arquivoFuncionarios >> novoFuncionario.nome >> novoFuncionario.numero >> tipo;
            if (tipo == 'P') {
                novoFuncionario.tipo = PROFESSOR;
            } else {
                novoFuncionario.tipo = COORDENADOR;
            }
            funcionarios.push_back(novoFuncionario);
        }
        arquivoFuncionarios.close();
    } else {
        cout << "Erro ao abrir o arquivo funcionarios.csv para leitura.\n";
    }
}

void removerFuncionario(vector<Funcionario> &funcionarios)
{
    if (funcionarios.empty())
    {
        cout << "Nenhum funcionário cadastrado para remover.\n";
        return;
    }

    cout << "Escolha o número do funcionário para remover:\n";
    for (const Funcionario &funcionario : funcionarios)
    {
        cout << "Número: " << funcionario.numero << ", Nome: " << funcionario.nome << "\n";
    }

    int escolhaFuncionario;
    cin >> escolhaFuncionario;

    auto it = find_if(funcionarios.begin(), funcionarios.end(), [escolhaFuncionario](const Funcionario &funcionario)
                      { return funcionario.numero == escolhaFuncionario; });

    if (it != funcionarios.end())
    {
        funcionarios.erase(it);
        cout << "Funcionário removido com sucesso.\n";

        ofstream outFile("funcionarios.csv");
        for (const Funcionario &funcionario : funcionarios)
        {
            outFile << funcionario.numero << "," << funcionario.nome << "\n";
        }
    }
    else
    {
        cout << "Funcionário não encontrado.\n";
    }
}

