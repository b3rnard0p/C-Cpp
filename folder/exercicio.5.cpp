#include <iostream>
#include <vector> 
using namespace std;

int maiorValor(const vector<int>& vetor) {
  int maior = vetor[0];

  for (int i = 1; i < vetor.size(); i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
    }
  }

  return maior;
}

int main() {
  vector<int> vetor = {1, 5, 10, 2, 4};

  int maior = maiorValor(vetor);

  cout << "O maior valor do vetor é " << maior << endl;

  return 0;
}
