#include "stdli.h"

Lista lista;
int i, k;

//cria uma lista vazia
Lista* crialista(){
	Lista *lista;
	lista = (Lista*) malloc(sizeof(Lista));
	if(lista != NULL){
		lista->qtd = 0;
	}
	return lista;
}

//deleta toda a lista
void deletar(Lista* lista){
	lista->qtd = 0;
}

//imprime toda a lista
void imprime(Lista* lista){
	if(lista == NULL){
		printf("Lista invalida!\n\n\n");
		return;
	}
	printf("\n\nImprimindo Lista\n\n");
	for(i=0; i<lista->qtd; i++){
		printf("Nome: %s\n", lista->clientes[i].nome);
		printf("CPF: %s\n", lista->clientes[i].cpf);
		printf("---------------------------\n");
	}
	if(lista->qtd > 0){
		printf("Quantidade de Clientes: %d\n\n", lista->qtd);	
		return;
	}
	printf("Lista vazia!\n\n\n");
}


//buscar cliente e retorna indice
int buscar(Lista* lista, cliente cliente){
	if(lista == NULL){
		printf("Lista invalida!\n\n\n");
		return 0;
	}
	for(i=0; i<lista->qtd; i++){
		if((strcmp(cliente.nome, lista->clientes[i].nome) == 0) && (strcmp(cliente.cpf, lista->clientes[i].cpf) == 0)){
			printf("Elemento no indice: %d\n", (i+1));
			return (i + 1);
		}
	}
	printf("Cliente nao esta na lista!\n");
	return 0;
}

//remove qualquer cliente na posição desejada e retorna cliente
cliente removecliente(Lista* lista, int index){ //RETORNA CLIENTE
	if(index <= lista->qtd && index > 0){
		cliente removido;
		strcpy(removido.nome, lista->clientes[(index - 1)].nome);
		strcpy(removido.cpf, lista->clientes[(index - 1)].cpf);
		for(i=(index - 1); i<lista->qtd; i++){
			lista->clientes[i] = lista->clientes[i+1];
		}
		lista->qtd--;
		return removido;
	}else{
		printf("Erro: Posicao inexistente!");
	}
	cliente removido;
	//removido.nome = NULL;
	//removido.cpf = NULL;
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

//insere numa determinada posicao da lista
int inserircliente(Lista* lista, cliente cliente, int index){
	
	if(lista == NULL){
		return 0;
	}
	if(lista->qtd == MAX){
		return 0;
	}
	if(index > lista->qtd){
		lista->clientes[lista->qtd] = cliente;
		lista->qtd++;
		return 1;
	}
	
	for(i=0; i<lista->qtd; i++){
		if(i == index){
			for(k=lista->qtd; k >= index; k--){
				lista->clientes[k+1] = lista->clientes[k];
			}
		}
	}

	lista->clientes[index] = cliente;
	lista->qtd++;
	return 1;
}