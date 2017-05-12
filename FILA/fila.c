#include "stdli.h"

Fila fila;
int i, k;

//cria uma fila vazia
Fila* criafila(){
	Fila *fila;
	fila = (Fila*) malloc(sizeof(Fila));
	if(fila != NULL){
		fila->qtd = 0;
	}
	return fila;
}

//deleta toda a fila
void deletar(Fila* fila){
	fila->qtd = 0;
}

//imprime toda a fila
void imprime(Fila* fila){
	if(fila == NULL){
		printf("Fila invalida!\n\n\n");
		return;
	}
	printf("\n\nImprimindo Fila\n\n");
	for(i=0; i<fila->qtd; i++){
		printf("Nome: %s\n", fila->clientes[i].nome);
		printf("CPF: %s\n", fila->clientes[i].cpf);
		printf("---------------------------\n");
	}
	if(fila->qtd > 0){
		printf("Quantidade de Clientes: %d\n\n", fila->qtd);	
		return;
	}
	printf("Fila vazia!\n\n\n");
}


//remove cliente na primeira posição e retorna cliente
cliente removecliente(Fila* fila){ //RETORNA CLIENTE
	if(fila->qtd > 0){
		cliente removido;
		strcpy(removido.nome, fila->clientes[0].nome);
		strcpy(removido.cpf, fila->clientes[0].cpf);
		for(i=0; i<fila->qtd; i++){
			fila->clientes[i] = fila->clientes[i+1];
		}
		fila->qtd--;
		return removido;
	}else{
		printf("Erro: Fila vazia!");
	}
	cliente removido;
	return removido;
}

//imprime cliente removido
void imprimecliente(cliente cliente){
	printf("\n\nCliente--------------------\n");
	printf("Nome: %s\n", cliente.nome);
	printf("CPF: %s\n", cliente.cpf);
	printf("---------------------------\n");
	return;
}

//insere na ultima posicao da fila
int inserircliente(Fila* fila, cliente cliente){
	if(fila == NULL){
		return 0;
	}
	if(fila->qtd == MAX){
		return 0;
	}
	fila->clientes[fila->qtd] = cliente;
	fila->qtd++;
	return 1;
}