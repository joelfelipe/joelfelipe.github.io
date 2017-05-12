#include "stdli.h"

Pilha pilha;
int i, k;

//cria uma pilha vazia
Pilha* criapilha(){
	Pilha *pilha;
	pilha = (Pilha*) malloc(sizeof(Pilha));
	if(pilha != NULL){
		pilha->qtd = 0;
	}
	return pilha;
}

//insere na ultima posicao da pilha
int inserircliente(Pilha* pilha, cliente cliente){
	if(pilha == NULL){
		return 0;
	}
	if(pilha->qtd == MAX){
		return 0;
	}
	pilha->clientes[pilha->qtd] = cliente;
	pilha->qtd++;
	return 1;
}

//remove cliente na ultima posição e retorna cliente
cliente removecliente(Pilha* pilha){ //RETORNA CLIENTE
	if(pilha->qtd > 0){
		cliente removido;
		strcpy(removido.nome, pilha->clientes[(pilha->qtd - 1)].nome);
		strcpy(removido.cpf, pilha->clientes[(pilha->qtd - 1)].cpf);
		pilha->qtd--;
		return removido;
	}else{
		printf("Erro: Pilha vazia!");
	}
	cliente removido;
	return removido;
}

//deleta toda a pilha
void deletar(Pilha* pilha){
	pilha->qtd = 0;
}

//imprime toda a pilha
void imprime(Pilha* pilha){
	if(pilha == NULL){
		printf("Pilha invalida!\n\n\n");
		return;
	}
	printf("\n\nImprimindo Pilha\n\n");
	for(i=0; i<pilha->qtd; i++){
		printf("Nome: %s\n", pilha->clientes[i].nome);
		printf("CPF: %s\n", pilha->clientes[i].cpf);
		printf("---------------------------\n");
	}
	if(pilha->qtd > 0){
		printf("Quantidade de Clientes: %d\n\n", pilha->qtd);	
		return;
	}
	printf("Pilha vazia!\n\n\n");
}

//imprime cliente removido
void imprimecliente(cliente cliente){
	printf("\n\nCliente--------------------\n");
	printf("Nome: %s\n", cliente.nome);
	printf("CPF: %s\n", cliente.cpf);
	printf("---------------------------\n");
	return;
}
