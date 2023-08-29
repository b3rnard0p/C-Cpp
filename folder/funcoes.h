//Exercicio 1
int calcularQuadrado(int n) {
  return n * n;
}
//Com retorno

//Exercicio 2
int contaPalavras(const std::string& frase) {
  int numeroDePalavras = 0;

  for (int i = 0; i < frase.size(); i++) {
    if (frase[i] == ' ') {
      numeroDePalavras++;
    }
  }

  return numeroDePalavras + 1;
}
//Com retorno

//Exercicio 3
bool ehPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }

    for (int i = 2; i * i <= numero; ++i) {
        if (numero % i == 0) {
            return false;
        }
    }

    return true;
}
//Com retorno

//Exercicio 4
int calcularIdade(int anoAtual, int anoNascimento) {
    return anoAtual - anoNascimento;
}
//Com retorno

//Exercicio 5

//Com retorno

//Exercicio 6

//Sem retorno

//Exercicio 7


//Exercicio 8
bool isAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool isDataValida(int dia, int mes, int ano) {
    if (ano >= 0 && mes >= 1 && mes <= 12) {
        int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isAnoBissexto(ano)) {
            diasNoMes[2] = 29;
        }

        return dia >= 1 && dia <= diasNoMes[mes];
    }

    return false;
}

//Exercicio 9


//Exercicio 10
