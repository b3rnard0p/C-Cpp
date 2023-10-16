#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Definindo a estrutura para Criptomoeda
struct Criptomoeda {
    string nome;
    string sigla;
    double valorDolar;
};

// Função para converter uma string em maiúsculas
string converterMaiusculas(string texto) {
    string textoMaiusculo;
    for (char c : texto) {
        textoMaiusculo += toupper(c);
    }
    return textoMaiusculo;
}

// Função para cadastrar uma nova criptomoeda
void cadastrar(Criptomoeda* &vetor, int &totalCriptomoedas, int &capacidade) {
    if (totalCriptomoedas >= capacidade) {
        // Vetor cheio, aloque mais memória
        capacidade += 10; // Aumente a capacidade em um valor apropriado
        Criptomoeda* novoVetor = new Criptomoeda[capacidade];
        for (int i = 0; i < totalCriptomoedas; i++) {
            novoVetor[i] = vetor[i];
        }
        delete[] vetor; // Libere a memória do vetor antigo
        vetor = novoVetor; // Aponte o vetor para o novo vetor alocado
    }

    cout << "CADASTRAR CRIPTOMOEDA" << endl;

    cout << "Nome: ";
    cin >> vetor[totalCriptomoedas].nome;

    cout << "Sigla: ";
    cin >> vetor[totalCriptomoedas].sigla;
    vetor[totalCriptomoedas].sigla = converterMaiusculas(vetor[totalCriptomoedas].sigla);

    cout << "Valor em dólar: ";
    cin >> vetor[totalCriptomoedas].valorDolar;

    totalCriptomoedas++;
    cout << "Criptomoeda cadastrada com sucesso." << endl;
}

// Função para atualizar o valor de uma criptomoeda
void atualizar(Criptomoeda* vetor, int totalCriptomoedas) {
    if (totalCriptomoedas == 0) {
        cout << "A base de dados está vazia. Não é possível atualizar criptomoedas." << endl;
        return;
    }

    cout << "ATUALIZAR VALOR DA CRIPTOMOEDA" << endl;

    string sigla;
    cout << "Informe a sigla da criptomoeda a ser atualizada: ";
    cin >> sigla;
    sigla = converterMaiusculas(sigla);

    for (int i = 0; i < totalCriptomoedas; i++) {
        if (vetor[i].sigla == sigla) {
            cout << "Novo valor em dólar: ";
            cin >> vetor[i].valorDolar;
            cout << "Valor atualizado com sucesso." << endl;
            return;
        }
    }

    cout << "Criptomoeda não encontrada." << endl;
}

// Função para remover uma criptomoeda
void remover(Criptomoeda* vetor, int &totalCriptomoedas) {
    if (totalCriptomoedas == 0) {
        cout << "A base de dados está vazia. Não é possível remover criptomoedas." << endl;
        return;
    }

    cout << "REMOVER CRIPTOMOEDA" << endl;

    string sigla;
    cout << "Informe a sigla da criptomoeda a ser removida: ";
    cin >> sigla;
    sigla = converterMaiusculas(sigla);

    for (int i = 0; i < totalCriptomoedas; i++) {
        if (vetor[i].sigla == sigla) {
            for (int j = i; j < totalCriptomoedas - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            totalCriptomoedas--;
            cout << "Criptomoeda removida com sucesso." << endl;
            return;
        }
    }

    cout << "Criptomoeda não encontrada." << endl;
}

// Função para listar todas as criptomoedas
void listar(Criptomoeda* vetor, int totalCriptomoedas) {
    if (totalCriptomoedas == 0) {
        cout << "A base de dados está vazia." << endl;
        return;
    }

    cout << "LISTA DE CRIPTOMOEDAS" << endl;
    for (int i = 0; i < totalCriptomoedas; i++) {
        cout << "Nome: " << vetor[i].nome << ", Sigla: " << vetor[i].sigla << ", Valor em dólar: " << vetor[i].valorDolar << endl;
    }
}

// Função para salvar as criptomoedas em um arquivo "cripto.csv"
void salvarCriptomoedas(const Criptomoeda* vetor, int totalCriptomoedas) {
    ofstream arquivoCripto("cripto.csv");

    if (arquivoCripto.is_open()) {
        for (int i = 0; i < totalCriptomoedas; i++) {
            arquivoCripto << vetor[i].nome << "," << vetor[i].sigla << "," << vetor[i].valorDolar << "\n";
        }
        arquivoCripto.close();
        cout << "Criptomoedas salvas com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo cripto.csv." << endl;
    }
}

// Função para carregar as criptomoedas de um arquivo "cripto.csv"
void carregarCriptomoedas(Criptomoeda* &vetor, int &totalCriptomoedas, int &capacidade) {
    ifstream arquivoCripto("cripto.csv");

    if (arquivoCripto.is_open()) {
        totalCriptomoedas = 0;
        string linha;

        while (getline(arquivoCripto, linha)) {
            size_t pos = linha.find(",");
            if (pos != string::npos) {
                if (totalCriptomoedas >= capacidade) {
                    // Vetor cheio, aloque mais memória
                    capacidade += 10; // Aumente a capacidade em um valor apropriado
                    Criptomoeda* novoVetor = new Criptomoeda[capacidade];
                    for (int i = 0; i < totalCriptomoedas; i++) {
                        novoVetor[i] = vetor[i];
                    }
                    delete[] vetor; // Libere a memória do vetor antigo
                    vetor = novoVetor; // Aponte o vetor para o novo vetor alocado
                }
                vetor[totalCriptomoedas].nome = linha.substr(0, pos);
                linha = linha.substr(pos + 1);
                pos = linha.find(",");
                if (pos != string::npos) {
                    vetor[totalCriptomoedas].sigla = linha.substr(0, pos);
                    vetor[totalCriptomoedas].valorDolar = stod(linha.substr(pos + 1));
                    totalCriptomoedas++;
                }
            }
        }
        arquivoCripto.close();
    } else {
        cout << "Erro ao abrir o arquivo cripto.csv. Criando uma base de dados vazia." << endl;
    }
}

int main() {
    Criptomoeda* vetor = nullptr; // Ponteiro para o vetor de criptomoedas
    int totalCriptomoedas = 0;
    int capacidade = 0; // Capacidade atual do vetor

    carregarCriptomoedas(vetor, totalCriptomoedas, capacidade);

    int opcao;

    do {
        cout << "MENU" << endl;
        cout << "1 - Cadastrar Criptomoeda" << endl;
        cout << "2 - Atualizar Valor" << endl;
        cout << "3 - Remover Criptomoeda" << endl;
        cout << "4 - Listar Criptomoedas" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrar(vetor, totalCriptomoedas, capacidade);
                salvarCriptomoedas(vetor, totalCriptomoedas);
                break;
            case 2:
                atualizar(vetor, totalCriptomoedas);
                salvarCriptomoedas(vetor, totalCriptomoedas);
                break;
            case 3:
                remover(vetor, totalCriptomoedas);
                salvarCriptomoedas(vetor, totalCriptomoedas);
                break;
            case 4:
                listar(vetor, totalCriptomoedas);
                break;
            case 5:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (opcao != 5);

    delete[] vetor; // Libere a memória alocada para o vetor

    return 0;
}
