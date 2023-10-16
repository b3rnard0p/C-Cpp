/**
 * A loja VendeTudo possui 50 clientes. 
 * O gerente, para cada cliente, necessita armazenar o nome, cidade onde mora, o total da compra e o m�s 
 * que o cliente comprou.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 50

typedef struct {
    char nome[50];
    char cidade[50];
    float compras;
    char mes[100];
} Cliente;

int main() {
    Cliente vetor[TAM];
    int opcao;
    
     setlocale(LC_ALL, "Portuguese");

    for (int i = 0; i < TAM; i++) {
        printf("Nome do cliente: ");
        scanf("%s", vetor[i].nome);
        fflush(stdin);

        printf("Cidade onde mora: ");
        scanf("%s", vetor[i].cidade);
        fflush(stdin);

        printf("N�mero de compras: ");
        scanf("%f", &vetor[i].compras);
        fflush(stdin);

        printf("M�s da compra: ");
        scanf("%s", vetor[i].mes);

        printf("1 - Continuar; 2 - Sair: ");
        scanf("%d", &opcao);
        fflush(stdin);

        if (opcao != 1) {
            break;
        }
    }

    printf("\n\nCLIENTES CADASTRADOS\n");

    for (int i = 0; i < TAM; i++) {
        if (vetor[i].nome[0] == '\0') {
            break;
        }
        printf("%s\n%s\nR$ %.2f\n%s\n", vetor[i].nome, vetor[i].cidade, vetor[i].compras, vetor[i].mes);
        printf("--------------------\n");
    }

    return 0;
}
