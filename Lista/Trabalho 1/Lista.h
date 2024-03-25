// Gerar uma lista de tamanho M com números aleatórios
vector<int> gerarListaAleatoria(int tamanho) {
    vector<int> lista;
    for (int i = 0; i < tamanho; ++i) {
        lista.push_back(rand() % 100); // Números aleatórios de 0 a 99
    }
    return lista;
}

// Mostrar os conteúdos das N listas
void mostrarConteudos(const vector<vector<int>>& listas) {
    for (int i = 0; i < listas.size(); ++i) {
        cout << "Lista " << i + 1 << ": ";
        for (int j = 0; j < listas[i].size(); ++j) {
            cout << listas[i][j] << " ";
        }
        cout << endl;
    }
}

// Mostrar os números que aparecem nas N listas
void mostrarNumerosNasListas(const vector<vector<int>>& listas) {
    unordered_set<int> numerosComuns;
    for (int i = 0; i < listas.size(); ++i) {
        for (int j = 0; j < listas[i].size(); ++j) {
            numerosComuns.insert(listas[i][j]);
        }
    }
    cout << "Números que aparecem nas listas:" << endl;
    for (int num : numerosComuns) {
        cout << num << " ";
    }
    cout << endl;
}

// Mostrar os números que aparecem somente em uma das N listas
void mostrarNumerosUmaLista(const vector<vector<int>>& listas) {
    unordered_set<int> numerosUnicos;
    for (int i = 0; i < listas.size(); ++i) {
        for (int j = 0; j < listas[i].size(); ++j) {
            int num = listas[i][j];
            bool apareceApenasUmaVez = true;
            for (int k = 0; k < listas.size(); ++k) {
                if (i != k && find(listas[k].begin(), listas[k].end(), num) != listas[k].end()) {
                    apareceApenasUmaVez = false;
                    break;
                }
            }
            if (apareceApenasUmaVez) {
                numerosUnicos.insert(num);
            }
        }
    }
    cout << "Números que aparecem somente em uma das listas:" << endl;
    for (int num : numerosUnicos) {
        cout << num << " ";
    }
    cout << endl;
}