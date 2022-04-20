//tenteando menu

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	char nome [30], email[40];
	int cpf, id, op;
	
   	while(op!=3){
	   	printf("\nMENU DE OPÇÕES\n");
	  	printf("[1] Cadastrar\n");
    		printf("[2] Consultar\n");
		printf("[3] Sair\n");
		printf("Insira a opção:\n");
	    	scanf("%d", &op);
	
		switch (op){
			case 1:
                    	printf("Insira o ID a ser cadastrado.\n");
                    	scanf("%d", &id);
				printf("Insira o nome: \n");
				scanf("%s", nome);
				printf("Insira o email: \n");
				scanf("%s", email);
				fflush(stdin);
				printf("Insira o cpf: \n");
				scanf("%d", &cpf);
				printf("Cliente cadastrado com sucesso.\n");
				break;		
			case 2: 
				printf("Insira o ID do cliente: \n");
				scanf("%d", &id);
				printf("ID: %d\n", id);
				printf("Nome: %s \n", nome);
				printf("Email: %s \n", email);
				printf("CPF: %d \n", cpf);
				break;
			case 3: 
			    	exit(1);
				printf("Pressione ENTER para sair");
				break;
			default: 
			    	printf("Opção inválida.");
			    	break;
		}
	}
	
	return 0;
}
