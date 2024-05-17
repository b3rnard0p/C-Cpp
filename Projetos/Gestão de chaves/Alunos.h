void cadastrarAluno(vector<Aluno>& alunos) {
    Aluno novoAluno;
    cout << "Digite o nome do aluno: ";
    cin >> novoAluno.nome;
    cout << "Digite o numero do aluno: ";
    cin >> novoAluno.numero;
    alunos.push_back(novoAluno);
    cout << "Aluno cadastrado com sucesso!\n";

    ofstream arquivo("alunos.csv", ios::app);  

    if (arquivo.is_open()) {
        arquivo << novoAluno.nome << "," << novoAluno.numero << "\n";
        arquivo.close();
        cout << "Dados do aluno salvo em alunos.csv.\n";
    } else {
        cout << "Erro ao abrir o arquivo alunos.csv para escrita.\n";
    }
}

void listarAlunos(const vector<Aluno> &alunos)
{
    cout << "Lista de Alunos:\n";
    for (const Aluno &aluno : alunos)
    {
        cout << "Nome: " << aluno.nome << ", Numero: " << aluno.numero << "\n";
    }
}


void lerAlunos(vector<Aluno>& alunos) {
    ifstream arquivoAlunos("alunos.csv");
    if (arquivoAlunos.is_open()) {
        while (!arquivoAlunos.eof()) {
            Aluno novoAluno;
            arquivoAlunos >> novoAluno.nome >> novoAluno.numero;
            alunos.push_back(novoAluno);
        }
        arquivoAlunos.close();
    } else {
        cout << "Erro ao abrir o arquivo alunos.csv para leitura.\n";
    }
}

void removerAluno(vector<Aluno> &alunos)
{
    if (alunos.empty())
    {
        cout << "Nenhum aluno cadastrado para remover.\n";
        return;
    }

    cout << "Escolha o número do aluno para remover:\n";
    for (const Aluno &aluno : alunos)
    {
        cout << "Número: " << aluno.numero << ", Nome: " << aluno.nome << "\n";
    }

    int escolhaAluno;
    cin >> escolhaAluno;

    auto it = find_if(alunos.begin(), alunos.end(), [escolhaAluno](const Aluno &aluno)
                      { return aluno.numero == escolhaAluno; });

    if (it != alunos.end())
    {
        alunos.erase(it);
        cout << "Aluno removido com sucesso.\n";

        ofstream outFile("alunos.csv");
        for (const Aluno &aluno : alunos)
        {
            outFile << aluno.numero << "," << aluno.nome << "\n";
        }
    }
    else
    {
        cout << "Aluno não encontrado.\n";
    }
}