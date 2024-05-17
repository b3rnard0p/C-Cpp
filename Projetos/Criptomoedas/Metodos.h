string converterMaiusculas(string texto) {
    string textoMaiusculo;
    for (char c : texto) {
        textoMaiusculo += toupper(c);
    }
    return textoMaiusculo;
}

void cadastrar(Criptomoeda* &vetor, int &totalCriptomoedas, int &capacidade) {
    if (totalCriptomoedas >= capacidade) {
        // Vetor cheio, aloque mais memória
        capacidade += 1; // Aumente a capacidade em um valor apropriado
        Criptomoeda* novoVetor = new Criptomoeda[capacidade];
        for (int i = 0; i < totalCriptomoedas; i++) {
            novoVetor[i] = vetor[i];
        }
        delete[] vetor; // Libere a memória do vetor antigo
        vetor = novoVetor; // Aponte o vetor para o novo vetor alocado
    }

    cout << "CADASTRAR CRIPTOMOEDA" << endl;

    cout << "Nome: ";
    cin >> vetor[totalCriptomoedas].nome;

    cout << "Sigla: ";
    cin >> vetor[totalCriptomoedas].sigla;
    vetor[totalCriptomoedas].sigla = converterMaiusculas(vetor[totalCriptomoedas].sigla);

    cout << "Valor em dolar: ";
    cin >> vetor[totalCriptomoedas].valorDolar;

    totalCriptomoedas++;
    cout << "Criptomoeda cadastrada com sucesso." << endl;
}

void atualizar(Criptomoeda* vetor, int totalCriptomoedas) {
    if (totalCriptomoedas == 0) {
        cout << "A base de dados está vazia. Não é possível atualizar criptomoedas." << endl;
        return;
    }

    cout << "ATUALIZAR VALOR DA CRIPTOMOEDA" << endl;

    string sigla;
    cout << "Informe a sigla da criptomoeda a ser atualizada: ";
    cin >> sigla;
    sigla = converterMaiusculas(sigla);

    for (int i = 0; i < totalCriptomoedas; i++) {
        if (vetor[i].sigla == sigla) {
            cout << "Novo valor em dolar: ";
            cin >> vetor[i].valorDolar;
            cout << "Valor atualizado com sucesso." << endl;
            return;
        }
    }

    cout << "Criptomoeda não encontrada." << endl;
}

void remover(Criptomoeda* vetor, int &totalCriptomoedas) {
    if (totalCriptomoedas == 0) {
        cout << "A base de dados está vazia. Não é possível remover criptomoedas." << endl;
        return;
    }

    cout << "REMOVER CRIPTOMOEDA" << endl;

    string sigla;
    cout << "Informe a sigla da criptomoeda a ser removida: ";
    cin >> sigla;
    sigla = converterMaiusculas(sigla);

    for (int i = 0; i < totalCriptomoedas; i++) {
        if (vetor[i].sigla == sigla) {
            for (int j = i; j < totalCriptomoedas - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            totalCriptomoedas--;
            cout << "Criptomoeda removida com sucesso." << endl;
            return;
        }
    }

    cout << "Criptomoeda não encontrada." << endl;
}

void listar(Criptomoeda* vetor, int totalCriptomoedas) {
    if (totalCriptomoedas == 0) {
        cout << "A base de dados está vazia." << endl;
        return;
    }

    cout << "LISTA DE CRIPTOMOEDAS" << endl;
    for (int i = 0; i < totalCriptomoedas; i++) {
        cout << "Nome: " << vetor[i].nome << ", Sigla: " << vetor[i].sigla << ", Valor em dolar: " << "U$" << vetor[i].valorDolar << endl;
    }
}

// Função para salvar as criptomoedas em um arquivo "cripto.csv"
void salvarCriptomoedas(const Criptomoeda* vetor, int totalCriptomoedas) {
    ofstream arquivoCripto("cripto.csv");

    if (arquivoCripto.is_open()) {
        for (int i = 0; i < totalCriptomoedas; i++) {
            arquivoCripto << vetor[i].nome << "," << vetor[i].sigla << "," << vetor[i].valorDolar << "\n";
        }
        arquivoCripto.close();
        cout << "Criptomoedas salvas com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo cripto.csv." << endl;
    }
}

// Função para carregar as criptomoedas de um arquivo "cripto.csv"
void carregarCriptomoedas(Criptomoeda* &vetor, int &totalCriptomoedas, int &capacidade) {
    ifstream arquivoCripto("cripto.csv");

    if (arquivoCripto.is_open()) {
        totalCriptomoedas = 0;
        string linha;

        while (getline(arquivoCripto, linha)) {
            size_t pos = linha.find(",");
            if (pos != string::npos) {
                if (totalCriptomoedas >= capacidade) {
                    // Vetor cheio, aloque mais memória
                    capacidade += 1; // Aumente a capacidade em um valor apropriado
                    Criptomoeda* novoVetor = new Criptomoeda[capacidade];
                    for (int i = 0; i < totalCriptomoedas; i++) {
                        novoVetor[i] = vetor[i];
                    }
                    delete[] vetor; // Libere a memória do vetor antigo
                    vetor = novoVetor; // Aponte o vetor para o novo vetor alocado
                }
                vetor[totalCriptomoedas].nome = linha.substr(0, pos);
                linha = linha.substr(pos + 1);
                pos = linha.find(",");
                if (pos != string::npos) {
                    vetor[totalCriptomoedas].sigla = linha.substr(0, pos);
                    vetor[totalCriptomoedas].valorDolar = stod(linha.substr(pos + 1));
                    totalCriptomoedas++;
                }
            }
        }
        arquivoCripto.close();
    } else {
        cout << "Erro ao abrir o arquivo cripto.csv. Criando uma base de dados vazia." << endl;
    }
}
