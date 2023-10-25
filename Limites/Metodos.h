#include <iostream>
#include <cmath>
using namespace std;

// Função que calcula o limite de uma função afim
double calcularLimiteAfim(double a, double b, double x, char operador1, char raizOnde) {
    double resultado;
    double numerador;

    //Escolha do operador com resolução normal
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


    //Escolha do operador com resolução de raiz quadrada
    if(operador1 == '+'){
         if (raizOnde == 'a') {
        numerador = sqrt(a) * x + b;
    } else if (raizOnde == 'x') {
        numerador = a * sqrt(x) + b;
    } else if (raizOnde == 'b') {
        numerador = a * x + sqrt(b);
    } else if (raizOnde == 'n') {
        numerador = a * x + b;
    } else {
        cout << "Opção de raiz inválida." << endl;
        return NAN;
    }
    } else if(operador1 == '-'){
            if (raizOnde == 'a') {
        numerador = sqrt(a) * x - b;
    } else if (raizOnde == 'x') {
        numerador = a * sqrt(x) - b;
    } else if (raizOnde == 'b') {
        numerador = a * x - sqrt(b);
    } else if (raizOnde == 'n') {
        numerador = a * x - b;
    } else {
        cout << "Opção de raiz inválida." << endl;
        return NAN;
    }
    } else if (operador1 == '*'){
        if (raizOnde == 'a') {
        numerador = sqrt(a) * x * b;
    } else if (raizOnde == 'x') {
        numerador = a * sqrt(x) * b;
    } else if (raizOnde == 'b') {
        numerador = a * x * sqrt(b);
    } else if (raizOnde == 'n') {
        numerador = a * x / b;
    } else {
        cout << "Opção de raiz inválida." << endl;
        return NAN;
    }
    } else if (operador1 == '/'){
         if (raizOnde == 'a') {
        numerador = sqrt(a) * x / b;
    } else if (raizOnde == 'x') {
        numerador = a * sqrt(x) / b;
    } else if (raizOnde == 'b') {
        numerador = a * x / sqrt(b);
    } else if (raizOnde == 'n') {
        numerador = a * x / b;
    } else {
        cout << "Opção de raiz inválida." << endl;
        return NAN;
    }
    }

    if(raizOnde == 'a' || raizOnde == 'x' || raizOnde == 'b'){
        resultado = numerador;
    } else{
        return resultado;
    }
}

// Função que calcula o limite de uma função quadrática
double calcularLimiteQuadratica(double a, double b, double c, double x, char operador1, char operador2, char raizOnde ) {
    double numerador = a * x * x;

     //operador +
     if(operador1 == '+'){
        if (raizOnde == 'a') {
        numerador = sqrt(a) * (x * x) + b * x;
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
    } else if (raizOnde == 'b') {
        numerador = a * (x * x) + sqrt(b) * x;
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

    } else if (raizOnde == 'c') {
        numerador = a * (x * x) + b * x;
        if (operador2 == '+') {
        numerador += sqrt(c);
    } else if (operador2 == '-') {
        numerador -= sqrt(c);
    } else if (operador2 == '*') {
        numerador *= sqrt(c);
    } else if (operador2 == '/') {
        if (c == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return NAN;
        }
        numerador /= sqrt(c);
    } else {
        cout << "Operador 2 inválido." << endl;
        return NAN;
    }

    } else if (raizOnde == 'x') {
        numerador = a * (x * x) + b * sqrt(x);
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

    } else if (raizOnde == 'n') {
        numerador = a * (x * x) + b * x ;
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


    } else {
        cout << "Opção de raiz inválida." << endl;
        return NAN;
    }
     }

     //operador -
     if(operador1 == '-'){
        if (raizOnde == 'a') {
        numerador = sqrt(a) * (x * x) - b * x;
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
    } else if (raizOnde == 'b') {
        numerador = a * (x * x) - sqrt(b) * x;
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

    } else if (raizOnde == 'c') {
        numerador = a * (x * x) - b * x;
        if (operador2 == '+') {
        numerador += sqrt(c);
    } else if (operador2 == '-') {
        numerador -= sqrt(c);
    } else if (operador2 == '*') {
        numerador *= sqrt(c);
    } else if (operador2 == '/') {
        if (c == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return NAN;
        }
        numerador /= sqrt(c);
    } else {
        cout << "Operador 2 inválido." << endl;
        return NAN;
    }

    } else if (raizOnde == 'x') {
        numerador = a * (x * x) - b * sqrt(x);
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

    } else if (raizOnde == 'n') {
        numerador = a * (x * x) - b * x ;
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


    } else {
        cout << "Opção de raiz inválida." << endl;
        return NAN;
    }
     }

      //operador *
       if(operador1 == '*'){
        if (raizOnde == 'a') {
        numerador = sqrt(a) * (x * x) * b * x;
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
    } else if (raizOnde == 'b') {
        numerador = a * (x * x) * sqrt(b) * x;
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

    } else if (raizOnde == 'c') {
        numerador = a * (x * x) * b * x;
        if (operador2 == '+') {
        numerador += sqrt(c);
    } else if (operador2 == '-') {
        numerador -= sqrt(c);
    } else if (operador2 == '*') {
        numerador *= sqrt(c);
    } else if (operador2 == '/') {
        if (c == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return NAN;
        }
        numerador /= sqrt(c);
    } else {
        cout << "Operador 2 inválido." << endl;
        return NAN;
    }

    } else if (raizOnde == 'x') {
        numerador = a * (x * x) * b * sqrt(x);
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

    } else if (raizOnde == 'n') {
        numerador = a * (x * x) * b * x ;
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


    } else {
        cout << "Opção de raiz inválida." << endl;
        return NAN;
    }
     }

      //operador /
      if(operador1 == '/'){
        if (raizOnde == 'a') {
        numerador = sqrt(a) * (x * x) / b * x;
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
    } else if (raizOnde == 'b') {
        numerador = a * (x * x) / sqrt(b) * x;
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

    } else if (raizOnde == 'c') {
        numerador = a * (x * x) / b * x;
        if (operador2 == '+') {
        numerador += sqrt(c);
    } else if (operador2 == '-') {
        numerador -= sqrt(c);
    } else if (operador2 == '*') {
        numerador *= sqrt(c);
    } else if (operador2 == '/') {
        if (c == 0) {
            cout << "Divisão por zero não é permitida." << endl;
            return NAN;
        }
        numerador /= sqrt(c);
    } else {
        cout << "Operador 2 inválido." << endl;
        return NAN;
    }

    } else if (raizOnde == 'x') {
        numerador = a * (x * x) / b * sqrt(x);
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

    } else if (raizOnde == 'n') {
        numerador = a * (x * x) / b * x ;
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


    } else {
        cout << "Opção de raiz inválida." << endl;
        return NAN;
    }
     }

    double resultado = numerador;
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

double calcularLimiteExponencial(double a, double x) {
   double resultado = pow(a, x);
   return resultado;
}
