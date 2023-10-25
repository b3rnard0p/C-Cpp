// Função para calcular o fatorial de um n�mero
int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

// Função para calcular combinações (C(n, k))
int combinacao(int n, int k) {
    if (n < k) {
        return 0; // Retorna 0 se n for menor que k
    }
    return fatorial(n) / (fatorial(k) * fatorial(n - k));
}

// Função para calcular arranjos (A(n, k))
int arranjo(int n, int k) {
    if (n < k) {
        return 0; // Retorna 0 se n for menor que k
    }
    return fatorial(n) / fatorial(n - k);
}