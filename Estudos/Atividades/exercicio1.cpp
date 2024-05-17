#include<iostream>
using namespace std;


#include "funcoes.h"

int main() {
  int n = 5;
  int resultadoQuadrado = calcularQuadrado(n);

  std::cout << "O quadrado de " << n << " é " << resultadoQuadrado << std::endl;

  return 1;
}
