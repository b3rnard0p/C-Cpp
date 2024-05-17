typedef struct no {
    int dado;
    struct no *prox;
} Lista;

void exibir(Lista *lista) {
    Lista *p;
    for (p = lista; p; p = p->prox) {
        cout << p->dado << " ";
    }
}

bool localizar(int valor, Lista *lista) {
    Lista *p;
    for (p = lista; p; p = p->prox) {
        if (valor == p->dado)
            return true;
    }
    return false;
}

Lista *inserir(int valor, Lista *lista) {
    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));

    novo->dado = valor;
    novo->prox = NULL;

    Lista *p, *pR;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
        if (valor == p->dado) {
            free(novo);
            return lista;
        }
        if (valor < p->dado) {
            break;
        }
    }
    if (p == lista) {
        novo->prox = p;
        return novo;
    }
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

void localizarComunsEUnicos(vector<Lista *> &listas, vector<int> &numerosComuns, vector<int> &numerosUnicos) {
    vector<int> contador(101, 0); // Contador para armazenar a contagem de cada número

    // Percorrer todas as listas e contar quantas vezes cada número aparece
    for (auto lista : listas) {
        vector<bool> numerosNaLista(101, false); // Para evitar contagem duplicada do mesmo número na mesma lista
        for (Lista *p = lista; p; p = p->prox) {
            if (!numerosNaLista[p->dado]) {
                contador[p->dado]++;
                numerosNaLista[p->dado] = true;
            }
        }
    }

    // Verificar quais números estão presentes em todas as listas e quais estão presentes apenas uma vez
    for (int i = 1; i <= 100; ++i) {
        if (contador[i] == listas.size()) { // Presente em todas as listas
            numerosComuns.push_back(i);
        } else if (contador[i] == 1) { // Presente apenas em uma lista
            numerosUnicos.push_back(i);
        }
    }
}

Lista *criarLista(int tamanho) {
    Lista *lista = NULL;
    for (int i = 0; i < tamanho; ++i) {
        lista = inserir(rand() % 100 + 1, lista);
    }
    return lista;
}
