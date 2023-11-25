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

    auto it = find_if(alunos.begin(), alunos.end(), [escolhaAluno](const Aluno& aluno) {
        return aluno.numero == escolhaAluno;
    });

    if (it != alunos.end()) {
        auto permissaoIt = find_if(permissoes.begin(), permissoes.end(), [escolhaAluno](const PermissaoAluno& permissao) {
            return permissao.numero == escolhaAluno;
        });

        if (permissaoIt != permissoes.end()) {
            cout << "O aluno já possui permissão.\n";
        } else {
            PermissaoAluno novaPermissao;
            novaPermissao.numero = escolhaAluno;
            novaPermissao.permissao = true;
            permissoes.push_back(novaPermissao);
            cout << "Permissão concedida ao aluno.\n";

            ofstream arquivo("permissoes.csv", ios::app);
            if (arquivo.is_open()) {
                auto nomeAluno = it->nome;

                arquivo << nomeAluno << "," << novaPermissao.permissao << "\n";
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

bool verificarPermissaoAluno(const vector<PermissaoAluno>& permissoes, int numeroAluno) {
    for (const PermissaoAluno& permissao : permissoes) {
        if (permissao.numero == numeroAluno) {
            return permissao.permissao;
        }
    }
    return false; 
}

void listarAlunosPermitidos(const vector<Aluno> &alunos, const vector<PermissaoAluno> &permissoes)
{
    cout << "Lista de Alunos Permitidos:\n";
    for (const PermissaoAluno &permissao : permissoes)
    {
        auto alunoIt = find_if(alunos.begin(), alunos.end(), [permissao](const Aluno &aluno)
                               { return aluno.numero == permissao.numero; });

        if (alunoIt != alunos.end() && permissao.permissao)
        {
            cout << "Número: " << alunoIt->numero << ", Nome: " << alunoIt->nome << "\n";
        }
    }
}

void lerPermissoes(vector<PermissaoAluno>& permissoes) {
    ifstream arquivoPermissoes("permissoes.csv");
    if (arquivoPermissoes.is_open()) {
        while (!arquivoPermissoes.eof()) {
            PermissaoAluno permissao;
            arquivoPermissoes >> permissao.numero >> permissao.permissao;
            permissoes.push_back(permissao);
        }
        arquivoPermissoes.close();
    } else {
        cout << "Erro ao abrir o arquivo permissoes.csv para leitura.\n";
    }
}

void removerPermissaoAluno(vector<PermissaoAluno> &permissoes)
{
    if (permissoes.empty())
    {
        cout << "Nenhuma permissão de aluno cadastrada para remover.\n";
        return;
    }

    cout << "Escolha o número da permissão de aluno para remover:\n";
    for (const PermissaoAluno &permissao : permissoes)
    {
        cout << "Número: " << permissao.numero << ", Permissão: " << permissao.permissao << "\n";
    }

    int escolhaPermissao;
    cin >> escolhaPermissao;

    auto it = find_if(permissoes.begin(), permissoes.end(), [escolhaPermissao](const PermissaoAluno &permissao)
                      { return permissao.numero == escolhaPermissao; });

    if (it != permissoes.end())
    {
        permissoes.erase(it);
        cout << "Permissão de aluno removida com sucesso.\n";

        ofstream outFile("permissoes.csv");
        for (const PermissaoAluno &permissao : permissoes)
        {
            outFile << permissao.numero << "," << permissao.permissao << "\n";
        }
    }
    else
    {
        cout << "Permissão de aluno não encontrada.\n";
    }
}