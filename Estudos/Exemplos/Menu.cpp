#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define TAM 10

int main() {
    int opcao;
    char nome[200];
    int vetor[TAM];
    int i;

    do {
        system("cls");
        printf("1-Digite nome\n");
        printf("2-Sorteie numero\n");
        printf("3-Capture data e hora\n");
        printf("4-ocula e exibe vetor\n");
        printf("5-Sair\n");
        printf("Opcao:\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {

        case 1:
            printf("Nome:");
            gets(nome);
            printf("Voce digitou %d caracteres\n", strlen(nome));
            break;

        case 2:
            srand(time(NULL));
            printf("Numero: %d\n", rand() % 21);
            break;

        case 3: {
            time_t rawtime;
            time(&rawtime);
            char *timeString = ctime(&rawtime);
            printf("Data e Hora: %s", timeString);
            break;
        }

        case 4:
        	srand(time(NULL));
        	for(i=0;i<TAM;i++){
        		vetor[i]=rand()%50;
        		printf("%d\t",vetor[i]);
        	}
        	printf("\n");
            break;
        case 5:
        	
        	break;
        default:
            printf("Opcao invalida\n");
            break;
        }
        system("pause");
    } while (opcao != 5);

    return 0;
}


