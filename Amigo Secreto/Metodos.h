void salvarAmigos(const vector<Amigo>& amigos, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        for (const Amigo& amigo : amigos) {
            arquivo << amigo.nome << "," << amigo.email << "\n";
        }
        arquivo.close();
    } else {
        cout << "Erro ao criar o arquivo: " << nomeArquivo << endl;
    }
}

void carregarAmigos(vector<Amigo>& amigos, const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        amigos.clear();
        string linha;
        while (getline(arquivo, linha)) {
            size_t pos = linha.find(",");
            if (pos != string::npos) {
                Amigo novoAmigo;
                novoAmigo.nome = linha.substr(0, pos);
                novoAmigo.email = linha.substr(pos + 1);
                amigos.push_back(novoAmigo);
            }
        }
        arquivo.close();
    }
}

vector<Amigo> embaralharAmigosAteNinguemPegarSiMesmo(const vector<Amigo>& amigos) {
    vector<Amigo> amigosEmbaralhados = amigos;
    random_device rd;
    mt19937 g(rd());

    while (true) {
        shuffle(amigosEmbaralhados.begin(), amigosEmbaralhados.end(), g);

        bool alguemPegouSiMesmo = false;
        for (size_t i = 0; i < amigos.size(); ++i) {
            if (amigos[i].nome == amigosEmbaralhados[i].nome) {
                alguemPegouSiMesmo = true;
                break;
            }
        }

        if (!alguemPegouSiMesmo) {
            break;
        }
    }

    return amigosEmbaralhados;
}

void criarArquivoAmigoSecreto(const vector<Amigo>& listaAmigos, const vector<Amigo>& listaAmigosEmbaralhada, const string& nomeArquivo) {
    ofstream arquivoAmigoSecreto(nomeArquivo);

    if (arquivoAmigoSecreto.is_open()) {
        for (size_t i = 0; i < listaAmigos.size(); ++i) {
            arquivoAmigoSecreto << listaAmigos[i].nome << " tira " << listaAmigosEmbaralhada[i].nome << endl;
        }
        arquivoAmigoSecreto.close();
        cout << "Sorteio de Amigo Secreto concluído. Resultados no arquivo " << nomeArquivo << ".\n";
    } else {
        cout << "Erro ao criar o arquivo de Amigo Secreto.\n";
    }
}