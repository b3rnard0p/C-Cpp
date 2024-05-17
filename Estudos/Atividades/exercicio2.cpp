#include<iostream>
using namespace std;

#include "funcoes.h"

int main() {
  string frase = "Olá, mundo!";

  int numeroDePalavras = contaPalavras(frase);

  cout << "A frase '" << frase << "' tem " << numeroDePalavras << " palavras." << endl;

  return 0;
}
