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


void lerRegistrosChaves(const vector<Funcionario>& funcionarios, const vector<Aluno>& alunos) {
    ifstream arquivo("registro_chaves.csv");
    if (arquivo.is_open()) {
        cout << "\nRegistros de Chaves:\n";
        cout << "---------------------\n";

        while (arquivo) {
            string nomeUsuario, nomeSala, predio;

            getline(arquivo, nomeUsuario, ',');

            if (nomeUsuario.empty()) {
                break;
            }

            getline(arquivo, nomeSala, ',');
            getline(arquivo, predio, '\n');


            auto alunoIt = find_if(alunos.begin(), alunos.end(), [nomeUsuario](const Aluno& aluno) {
                return aluno.nome == nomeUsuario;
            });

            auto funcionarioIt = find_if(funcionarios.begin(), funcionarios.end(), [nomeUsuario](const Funcionario& funcionario) {
                return funcionario.nome == nomeUsuario;
            });

            if (alunoIt != alunos.end()) {
                cout << "Tipo: Aluno, Nome: " << nomeUsuario;
            } else if (funcionarioIt != funcionarios.end()) {
                cout << "Tipo: Funcionário, Nome: " << nomeUsuario;
            } else {
                cout << "Tipo: Desconhecido, Nome: " << nomeUsuario;
            }

            cout << ", Sala: " << nomeSala << ", Prédio: " << predio << "\n";
        }

        cout << "---------------------\n";
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo registro_chaves.csv para leitura.\n";
    }
} 

void pegarChaveSala(vector<PermissaoAluno> &permissoes, const vector<Funcionario> &funcionarios, vector<SalaAula> &salas, const vector<Aluno> &alunos, vector<string> &chavesPegas)
{
    if (salas.empty())
    {
        cout << "Nenhuma sala cadastrada.\n";
        return;
    }

    cout << "Você é um aluno com permissão (digite 'A') ou um funcionário (digite 'F')? ";
    char opcaoUsuario;
    cin >> opcaoUsuario;

    if (opcaoUsuario == 'A' || opcaoUsuario == 'a')
    {
        cout << "Escolha o aluno para pegar a chave:\n";

        for (size_t i = 0; i < permissoes.size(); ++i)
        {
            cout << i + 1 << " - Aluno: " << permissoes[i].numero << "\n";
        }

        size_t escolhaAluno;
        cin >> escolhaAluno;

        cout << "Escolha a sala para pegar a chave:\n";

        for (size_t i = 0; i < salas.size(); ++i)
        {
            auto it = find(chavesPegas.begin(), chavesPegas.end(), salas[i].nome);
            if (it == chavesPegas.end())
            {
                cout << i + 1 << " - Sala: " << salas[i].nome << ", Prédio: " << salas[i].predio << "\n";
            }
        }

        size_t escolhaSala;
        cin >> escolhaSala;

        if (escolhaSala > 0 && escolhaSala <= salas.size())
        {
            auto it = find(chavesPegas.begin(), chavesPegas.end(), salas[escolhaSala - 1].nome);
            if (it == chavesPegas.end())
            {
                salvarRegistroChave(alunos[escolhaAluno - 1].nome, salas[escolhaSala - 1].nome, salas[escolhaSala - 1].predio);
                chavesPegas.push_back(salas[escolhaSala - 1].nome);
                cout << "Aluno com permissão pegou a chave da sala: " << salas[escolhaSala - 1].nome << " no prédio " << salas[escolhaSala - 1].predio << "\n";
            }
            else
            {
                cout << "Sala já ocupada. Escolha outra sala.\n";
            }
        }
        else
        {
            cout << "Escolha de sala inválida.\n";
        }
    }
    else if (opcaoUsuario == 'F' || opcaoUsuario == 'f')
    {
        cout << "Escolha o Funcionário para pegar a chave:\n";

        for (size_t i = 0; i < funcionarios.size(); ++i)
        {
            cout << i + 1 << " - Funcionário: " << funcionarios[i].nome << ", Matrícula: " << funcionarios[i].numero << "\n";
        }

        size_t escolhaFuncionario;
        cin >> escolhaFuncionario;

        cout << "Escolha a sala para pegar a chave:\n";

        for (size_t i = 0; i < salas.size(); ++i)
        {
            auto it = find(chavesPegas.begin(), chavesPegas.end(), salas[i].nome);
            if (it == chavesPegas.end())
            {
                cout << i + 1 << " - Sala: " << salas[i].nome << ", Prédio: " << salas[i].predio << "\n";
            }
        }

        size_t escolhaSala;
        cin >> escolhaSala;

        if (escolhaSala > 0 && escolhaSala <= salas.size())
        {
            auto it = find(chavesPegas.begin(), chavesPegas.end(), salas[escolhaSala - 1].nome);
            if (it == chavesPegas.end())
            {
                salvarRegistroChave(funcionarios[escolhaFuncionario - 1].nome, salas[escolhaSala - 1].nome, salas[escolhaSala - 1].predio);
                chavesPegas.push_back(salas[escolhaSala - 1].nome);
                cout << "Funcionário pegou a chave da sala: " << salas[escolhaSala - 1].nome << "\n";
            }
            else
            {
                cout << "Sala já ocupada. Escolha outra sala.\n";
            }
        }
        else
        {
            cout << "Escolha de sala inválida.\n";
        }
    }
    else
    {
        cout << "Opção inválida. Tente novamente.\n";
    }
}
// ...

void listarChavesPegas(const vector<Funcionario> &funcionarios, const vector<Aluno> &alunos)
{
    lerRegistrosChaves(funcionarios, alunos);
}

void devolverChave(vector<SalaAula> &salas, vector<string> &chavesPegas)
{
    if (chavesPegas.empty())
    {
        cout << "Nenhuma chave foi pega.\n";
        return;
    }

    cout << "Escolha a sala para devolver a chave:\n";

    for (size_t i = 0; i < chavesPegas.size(); ++i)
    {
        cout << i + 1 << " - Sala: " << chavesPegas[i] << "\n";
    }

    size_t escolhaSala;
    cin >> escolhaSala;

    if (escolhaSala > 0 && escolhaSala <= chavesPegas.size())
    {
        string salaDevolvida = chavesPegas[escolhaSala - 1];
        chavesPegas.erase(chavesPegas.begin() + escolhaSala - 1);

        ifstream arquivoEntrada("registro_chaves.csv");
        ofstream arquivoSaidaTemporario("temporario.csv");

        if (arquivoEntrada.is_open() && arquivoSaidaTemporario.is_open())
        {
            string linha;
            while (getline(arquivoEntrada, linha))
            {
                if (linha.find(salaDevolvida) == string::npos)
                {
                    arquivoSaidaTemporario << linha << "\n";
                }
            }

            arquivoEntrada.close();
            arquivoSaidaTemporario.close();

            remove("registro_chaves.csv");
            rename("temporario.csv", "registro_chaves.csv");

            cout << "Chave devolvida com sucesso.\n";
        }
        else
        {
            cout << "Erro ao abrir os arquivos para remoção da chave.\n";
        }
    }
    else
    {
        cout << "Escolha de sala inválida.\n";
    }
}