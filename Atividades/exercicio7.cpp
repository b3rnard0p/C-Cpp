#include <iostream>
#include <unordered_map>
#include <string>
#include <locale>
using namespace std;

string obterNomeEstado(const string& sigla) {
    unordered_map<string, string> estados = {
        {"AC", "Acre"},
        {"AL", "Alagoas"},
        {"AP", "Amapá"},
        {"AM", "Amazonas"},
        {"BA", "Bahia"},
        {"CE", "Ceará"},
        {"DF", "Distrito Federal"},
        {"ES", "Espírito Santo"},
        {"GO", "Goiás"},
        {"MA", "Maranhão"},
        {"MG", "Minas Gerais"},
        {"MS", "Mato Grosso do Sul"},
        {"MT", "Mato Grosso"},
        {"PA", "Pará"},
        {"PB", "Paraíba"},
        {"PE", "Pernambuco"},
        {"PI", "Piauí"},
        {"PR", "Paraná"},
        {"RJ", "Rio de Janeiro"},
        {"RN", "Rio Grande do Norte"},
        {"RO", "Rondônia"},
        {"RR", "Roraima"},
        {"RS", "Rio Grande do Sul"},
        {"SC", "Santa Catarina"},
        {"SE", "Sergipe"},
        {"SP", "São Paulo"},
        {"TO", "Tocantins"}
    };

    string siglaUpperCase = sigla;
    locale loc;
    for (string::size_type i = 0; i < siglaUpperCase.length(); ++i) {
        siglaUpperCase[i] = toupper(siglaUpperCase[i], loc);
    }

    if (estados.find(siglaUpperCase) != estados.end()) {
        return estados[siglaUpperCase];
    } else {
        return "Estado não encontrado";
    }
}


int main() {
    string sigla;

    cout << "Digite a sigla de um estado brasileiro: ";
    cin >> sigla;

    string nomeEstado = obterNomeEstado(sigla);
    cout << "Nome completo do estado: " << nomeEstado << endl;

    return 0;
}
