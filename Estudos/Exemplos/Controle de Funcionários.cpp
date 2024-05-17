/**
 * Escreva um programa que fa�a o controle das informa��es relativas aos funcion�rios de uma determinada empresa. 
 * As informa��es que devem ser armazenadas s�o: NOME, SAL�RIO, CARGO, IDADE e SEXO. 
 * Defina a estrutura de dados e fa�a a leitura e exibi��o dos dados para um funcion�rio.
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
