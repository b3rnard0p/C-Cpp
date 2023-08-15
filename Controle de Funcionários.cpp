/**
 * Escreva um programa que faça o controle das informações relativas aos funcionários de uma determinada empresa. 
 * As informações que devem ser armazenadas são: NOME, SALÁRIO, CARGO, IDADE e SEXO. 
 * Defina a estrutura de dados e faça a leitura e exibição dos dados para um funcionário.
 */
 
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct {
    char nome[100];
    float salario;
    char cargo[100];
    int idade;
    char sexo;
}Funcionario;

main(){
	Funcionario x;
	
	printf("Lendo dados de um funcionario\n");
	printf("Nome: ");
	scanf("%s", x.nome);
	fflush(stdin);
	printf("Salario: ");
	scanf("%d", &x.salario);
	printf("Cargo: ");
	scanf("%s", x.cargo);
	fflush(stdin); 
	printf("Idade: ");
	scanf("%d", &x.idade);
	fflush(stdin);
	printf("Sexo: ");
	scanf("%c", &x.sexo);

	printf("Exibindo dados de um funcionario\n");
	printf("Nome: %s. Cargo: %s\n\n", x.nome, x.cargo);


	
	
	
	
	
	
	
	
	
	
}

