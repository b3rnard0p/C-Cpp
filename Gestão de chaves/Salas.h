void cadastrarSala(vector<SalaAula>& salas) {
    SalaAula novaSala;
    cout << "Digite o nome da sala: ";
    cin >> novaSala.nome;
    cout << "Digite o prédio: ";
    cin >> novaSala.predio;
    salas.push_back(novaSala);
    cout << "Sala cadastrada com sucesso!\n";

    ofstream arquivo("salas.csv", ios::app);  

    if (arquivo.is_open()) {
        arquivo << novaSala.nome << "," << novaSala.predio << "\n";
        arquivo.close();
        cout << "Dados da sala salvo em salas.csv.\n";
    } else {
        cout << "Erro ao abrir o arquivo salas.csv para escrita.\n";
    }
}

void listarSalas(const vector<SalaAula> &salas)
{
    cout << "Lista de Salas:\n";
    for (size_t i = 0; i < salas.size(); ++i)
    {
        cout << i + 1 << " - Sala: " << salas[i].nome << ", Prédio: " << salas[i].predio << "\n";
    }
}

void lerSalas(vector<SalaAula>& salas) {
    ifstream arquivoSalas("salas.csv");
    if (arquivoSalas.is_open()) {
        while (!arquivoSalas.eof()) {
            SalaAula novaSala;
            arquivoSalas >> novaSala.nome >> novaSala.predio;
            salas.push_back(novaSala);
        }
        arquivoSalas.close();
    } else {
        cout << "Erro ao abrir o arquivo salas.csv para leitura.\n";
    }
}

void removerSala(vector<SalaAula> &salas)
{
    if (salas.empty())
    {
        cout << "Nenhuma sala cadastrada para remover.\n";
        return;
    }

    cout << "Escolha o número da sala para remover:\n";
    for (const SalaAula &sala : salas)
    {
        cout << "Número: " << sala.predio << ", Nome: " << sala.nome << "\n";
    }

    int escolhaSala;
    cin >> escolhaSala;

    auto it = find_if(salas.begin(), salas.end(), [escolhaSala](const SalaAula &sala)
                      { return sala.predio == std::to_string(escolhaSala); });

    if (it != salas.end())
    {
        salas.erase(it);
        cout << "Sala removida com sucesso.\n";

        ofstream outFile("salas.csv");
        for (const SalaAula &sala : salas)
        {
            outFile << sala.predio << "," << sala.nome << "\n";
        }
    }
    else
    {
        cout << "Sala não encontrada.\n";
    }
}