#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 50
 typedef struct {
     char nome[100];
     int numeroFaltas;
     float nota1;
     float nota2;
     float nota3;
     float media;
     float valorMensalidade;
 } Aluno;

 int main() {
    Aluno vetor[50];
    int opcao;
    
     setlocale(LC_ALL, "Portuguese");

    int i = 0;
    do {
        system("cls");
        printf("Sistema Acad�mico\n\n");
        printf("Nome: ");
        gets(vetor[i].nome);
        fflush(stdin);

        printf("N�mero de faltas: ");
        scanf("%d", &vetor[i].numeroFaltas);
        fflush(stdin);

        printf("Nota 1: ");
        scanf("%f", &vetor[i].nota1);
        fflush(stdin);

        printf("Nota 2: ");
        scanf("%f", &vetor[i].nota2);
        fflush(stdin);

        printf("Nota 3: ");
        scanf("%f", &vetor[i].nota3);
        fflush(stdin);

        vetor[i].media = (vetor[i].nota1 + vetor[i].nota2 + vetor[i].nota3) / 3;

        printf("Valor da mensalidade: ");
        scanf("%f", &vetor[i].valorMensalidade);
        fflush(stdin);
        
        i++;

        if (i == TAM) {
            printf("Estrutura lotou... sistema encerrando ...");
            break;
        }
        printf("1 - Continua; 2 - Termina: ");
        scanf("%d", &opcao);
        fflush(stdin);
    } while (opcao == 1);

    printf("Exibindo dados de alunos cadastrados!!\n\n");
    int iAux;
    for (iAux = 0; iAux < i; iAux++) {
        printf("Aluno      : %s\n", vetor[iAux].nome);
        printf("Faltas     : %d\n", vetor[iAux].numeroFaltas);
        printf("M�dia      : %.1f\n", vetor[iAux].media);
        printf("Mensalidade: R$%.2f\n", vetor[iAux].valorMensalidade);
        printf("============================\n");
    }


    return 1;
 }
