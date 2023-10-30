// Função para embaralhar a lista de amigos
void embaralharAmigos(vector<Amigo>& amigos) {
    random_device rd;
    mt19937 g(rd());
    shuffle(amigos.begin(), amigos.end(), g);
}

// Função para salvar a lista de amigos em um arquivo CSV
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