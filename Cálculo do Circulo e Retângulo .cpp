/**
 * Em um plano cartesiano, um círculo pode ser definido pelas coordenadas do centro e pelo raio, 
 * enquanto um retângulo de lados paralelos aos eixos pode ser definido pelas coordenadas dos 
 * vértices superior esquerdo e inferior direito. Escreva um programa que leia os valores que definem 
 * um retângulo e um círculo, e verifique qual tem o maior perímetro e qual tem a maior área.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

typedef struct {
    int x, y;
    int raio;
    int perimetro;
    int area;
} Circulo;

typedef struct {
    int xSuperiorEsq;
    int ySuperiorEsq;
    int xInferiorDir;
    int yInferiorDir;
    int altura;
    int base;
    int perimetro;
    int area;
} Retangulo;

void lerCoordenadas(int *x, int *y) {
    printf("Digite coordenada x: ");
    scanf("%d", x);
    printf("Digite coordenada y: ");
    scanf("%d", y);
}

int calcularPerimetro(int a, int b) {
    return 2 * (a + b);
}

int calcularArea(int a, int b) {
    return a * b;
}

int main() {
    Circulo c;
    Retangulo r;

    printf("Lendo dados de um circulo\n");
    lerCoordenadas(&c.x, &c.y);
    printf("Digite o raio do circulo: ");
    scanf("%d", &c.raio);
    c.perimetro = 2 * PI * c.raio;
    c.area = PI * pow(c.raio, 2);

    printf("Lendo dados de um retangulo\n");
    lerCoordenadas(&r.xSuperiorEsq, &r.ySuperiorEsq);
    lerCoordenadas(&r.xInferiorDir, &r.yInferiorDir);

    r.altura = abs(r.ySuperiorEsq - r.yInferiorDir);
    r.base = abs(r.xSuperiorEsq - r.xInferiorDir);
    r.perimetro = calcularPerimetro(r.altura, r.base);
    r.area = calcularArea(r.altura, r.base);

    if (c.area > r.area) {
        printf("Circulo tem area maior: %d\n", c.area);
    } else {
        printf("Retangulo tem area maior: %d\n", r.area);
    }

    if (c.perimetro > r.perimetro) {
        printf("Circulo tem perimetro maior: %d\n", c.perimetro);
    } else {
        printf("Retangulo tem perimetro maior: %d\n", r.perimetro);
    }
    
    return 0;
}

