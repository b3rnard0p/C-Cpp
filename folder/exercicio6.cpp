#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void numerosComuns(const vector<int>& vetor1, const vector<int>& vetor2) {
    unordered_set<int> conjunto(vetor1.begin(), vetor1.end());
    cout << "Números comuns nos vetores: ";

    for (int num : vetor2) {
        if (conjunto.count(num)) {
            cout << num << " ";
            conjunto.erase(num); 
        }
    }

    cout << endl;
}

int main() {
    vector<int> vetor1 = {1, 2, 3, 4, 5};
    vector<int> vetor2 = {3, 4, 5, 6, 7};

    numerosComuns(vetor1, vetor2);

    return 0;
}
