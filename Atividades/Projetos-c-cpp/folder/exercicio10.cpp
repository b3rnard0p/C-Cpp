#include <iostream>
#include <string>

bool nomeEstaCompleto(const std::string& nome) {
    for (char c : nome) {
        if (std::isspace(c)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string nome;

    std::cout << "Digite um nome: ";
    std::getline(std::cin, nome);

    if (nomeEstaCompleto(nome)) {
        std::cout << "O nome está completo." << std::endl;
    } else {
        std::cout << "O nome não está completo." << std::endl;
    }

    return 0;
}
