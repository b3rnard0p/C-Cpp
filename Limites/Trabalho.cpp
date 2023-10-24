#include <iostream>
#include <cmath>

using namespace std;

// Função que calcula o limite de uma função afim
double calcularLimiteAfim(double a, double b, double x, char operador1) {
    double resultado;

    if (operador1 == '+') {
        resultado = a * x + b;
    } else if (operador1 == '-') {
        resultado = a * x - b;
    } else if (operador1 == '*') {
        resultado = a * x * b;
    } else if (operador1 == '/') {
        if (b == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return NAN;
        }
        resultado = (a * x) / b;
    } else {
        cout << "Operador 1 inválido." << endl;
        return NAN;
    }

    return resultado;
}

// Função que calcula o limite de uma função quadrática
double calcularLimiteQuadratica(double a, double b, double c, double x, char operador1, char operador2) {
    double numerador = a * x * x;

    if (operador1 == '+') {
        numerador += b * x;
    } else if (operador1 == '-') {
        numerador -= b * x;
    } else if (operador1 == '*') {
        numerador *= b * x;
    } else if (operador1 == '/') {
        if (b == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return NAN;
        }
        numerador /= b * x;
    } else {
        cout << "Operador 1 inválido." << endl;
        return NAN;
    }

    if (operador2 == '+') {
        numerador += c;
    } else if (operador2 == '-') {
        numerador -= c;
    } else if (operador2 == '*') {
        numerador *= c;
    } else if (operador2 == '/') {
        if (c == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return NAN;
        }
        numerador /= c;
    } else {
        cout << "Operador 2 inválido." << endl;
        return NAN;
    }

    if (a == 0) {
        cout << "A equação não é quadrática." << endl;
        return NAN;
    }

    double resultado = numerador;
    return resultado;
}


// Função que calcula o limite de uma função quadrática com raiz quadrada
double calcularLimiteQuadraticaComRaiz(double a, double b, double c, double x, char operador1, char operador2, char raizOnde) {
    double numerador, denominador;

    if (raizOnde == 'a') {
        numerador = a * sqrt(x) * x;
        denominador = 1 / sqrt(x);
    } else if (raizOnde == 'b') {
        numerador = a * x * sqrt(x);
        denominador = 1 / sqrt(x);
    } else if (raizOnde == 'c') {
        numerador = a * x * x;
        denominador = 1 / sqrt(x);
    } else if (raizOnde == 'none') {
        numerador = a * sqrt(x) * sqrt(x);
        denominador = 1 / sqrt(x);
    } else {
        cout << "Opção de raiz inválida." << endl;
        return NAN;
    }

    if (operador1 == '+') {
        numerador += b * x;
    } else if (operador1 == '-') {
        numerador -= b * x;
    } else if (operador1 == '*') {
        numerador *= b * x;
    } else if (operador1 == '/') {
        if (b == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return NAN;
        }
        numerador /= b * x;
    } else {
        cout << "Operador 1 inválido." << endl;
        return NAN;
    }

    if (operador2 == '+') {
        numerador += c;
    } else if (operador2 == '-') {
        numerador -= c;
    } else if (operador2 == '*') {
        numerador *= c;
    } else if (operador2 == '/') {
        if (c == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return NAN;
        }
        numerador /= c;
    } else {
        cout << "Operador 2 inválido." << endl;
        return NAN;
    }

    if (a == 0) {
        cout << "A equação não é quadrática." << endl;
        return NAN;
    }

    double resultado = numerador / denominador;
    return resultado;
}

void calcularBhaskara(double a, double b, double c, double x) {
    double delta = b * b - 4 * a * c;

    if (delta > 0) {
        double raiz1 = (-b + sqrt(delta)) / (2 * a);
        double raiz2 = (-b - sqrt(delta)) / (2 * a);
        cout << "As raízes são reais e diferentes:" << endl;
        cout << "Raiz 1: " << raiz1 << endl;
        cout << "Raiz 2: " << raiz2 << endl;

        // Calcula o valor da equação a(x - raiz1)(x - raiz2)
        double valor = a * (x - raiz1) * (x - raiz2);
        cout << "Valor da equação a(x - raiz1)(x - raiz2): " << valor << endl;
    } else if (delta == 0) {
        double raiz = -b / (2 * a);
        cout << "A equação tem uma raiz real e repetida:" << endl;
        cout << "Raiz: " << raiz << endl;

        // Calcula o valor da equação a(x - raiz)^2
        double valor = a * (x - raiz) * (x - raiz);
        cout << "Valor da equação a(x - raiz)^2: " << valor << endl;
    } else {
        cout << "A equação não tem raízes reais." << endl;
    }
}

// Função que calcula o limite de uma função com raiz quadrada
double calcularLimiteRaizQuadrada(double a, double b, double x, char operador1) {
    if (x < 0) {
        cout << "Raiz quadrada de número negativo não é permitida." << endl;
        return NAN;
    }

    double resultado;
    if (operador1 == '+') {
        resultado = a * sqrt(x) + b;
    } else if (operador1 == '-') {
        resultado = -a * sqrt(x) - b;
    } else if (operador1 == '*') {
        resultado = a * sqrt(x) * b;
    } else if (operador1 == '/') {
        if (b == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return NAN;
        }
        resultado = (a * sqrt(x)) / b;
    } else {
        cout << "Operador 1 inválido." << endl;
        return NAN;
    }
    return resultado;
}

double calcularLimiteExponencial(double a, double x) {
    double resultado = pow(a, x);
    return resultado;
}

int main() {
    int escolha;
    double a, b, c, x, resultado;
    char operador1, operador2, raizOnde = 'none';

    cout << "Escolha o tipo de função:" << endl;
    cout << "1 - Função Afim (Ax + B)" << endl;
    cout << "2 - Função Quadrática (Ax^2 + Bx + C)" << endl;
    cout << "3 - Função Exponencial (Ae^(Ax))" << endl;
    cout << "4 - Função com Raiz Quadrada" << endl;
    cout << "Opção: ";
    cin >> escolha;

    if (escolha == 1) {
        cout << "Digite o valor de 'a': ";
        cin >> a;
        cout << "Digite o valor de 'b': ";
        cin >> b;
        cout << "Digite o valor de 'x': ";
        cin >> x;

        cout << "Escolha o operador 1 (+, -, *, /): ";
        cin >> operador1;

        resultado = calcularLimiteAfim(a, b, x, operador1);
    } else if (escolha == 2) {
        cout << "Digite o valor de 'a': ";
        cin >> a;
        cout << "Digite o valor de 'b': ";
        cin >> b;
        cout << "Digite o valor de 'c': ";
        cin >> c;
        cout << "Digite o valor de 'x': ";
        cin >> x;

        cout << "Escolha o operador 1 (+, -, *, /): ";
        cin >> operador1;
        cout << "Escolha o operador 2 (+, -, *, /): ";
        cin >> operador2;

        resultado = calcularLimiteQuadratica(a, b, c, x, operador1, operador2);
    } else if (escolha == 3) {
        cout << "Digite o valor de 'A': ";
        cin >> a;
        cout << "Digite o valor de 'x': ";
        cin >> x;

        resultado = calcularLimiteExponencial(a, x);
    } else if (escolha == 4) {
        int escolhaFuncao;
        cout << "Escolha o tipo de função com Raiz Quadrada:" << endl;
        cout << "1 - Função Afim (Ax^(1/2) + B)" << endl;
        cout << "2 - Função Quadrática (Ax^(1/2) + Bx + C)" << endl;
        cout << "Opção: ";
        cin >> escolhaFuncao;

        if (escolhaFuncao == 1) {
            cout << "Onde deseja colocar a raiz? (a, b, x): ";
            cin >> raizOnde;
            cout << "Digite o valor de 'a': ";
            cin >> a;
            cout << "Digite o valor de 'b': ";
            cin >> b;
            cout << "Digite o valor de 'x': ";
            cin >> x;

            cout << "Escolha o operador 1 (+, -, *, /): ";
            cin >> operador1;

            resultado = calcularLimiteRaizQuadrada(a, b, x, operador1);
        } else if (escolhaFuncao == 2) {
            cout << "Onde deseja colocar a raiz? (a, b, c, x): ";
            cin >> raizOnde;
            cout << "Digite o valor de 'a': ";
            cin >> a;
            cout << "Digite o valor de 'b': ";
            cin >> b;
            cout << "Digite o valor de 'c': ";
            cin >> c;
            cout << "Digite o valor de 'x': ";
            cin >> x;

            cout << "Escolha o operador 1 (+, -, *, /): ";
            cin >> operador1;
            cout << "Escolha o operador 2 (+, -, *, /): ";
            cin >> operador2;

            resultado = calcularLimiteQuadraticaComRaiz(a, b, c, x, operador1, operador2, raizOnde);
        } else {
            cout << "Escolha inválida." << endl;
            return 1;
        }
    } else {
        cout << "Escolha inválida." << endl;
        return 1;
    }

    if (std::isnan(resultado) || std::isinf(resultado)) {
        cout << "O limite resulta em uma indeterminação." << endl;
    } else {
        cout << "Resultado do limite: " << resultado << endl;
    }

    return 0;
}
