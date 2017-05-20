#include "lista.h"

struct lista{
	struct lista *ant;
	Cliente dados;
	struct lista *prox;
};
typedef struct lista Lis;

//Criar lista vazia
Lista* criarLista(){
	Lista* lista = (Lista*) malloc(sizeof(Lista));
	if(lista != NULL)
		*lista = NULL;
	return lista;
}

//Liberar lista
void deletarLista(Lista* lista){
	if(!listaVazia(lista)){
		Lis* aux;
		while(*lista != NULL){
			aux = *lista;
			*lista = (*lista)->prox;
			free(aux);
		}
		free(lista);
	}
}

//Inserir Elemento
int inserirElemento(Lista* lista, Cliente cliente, int posicao){
	int n = 0;
	Lis *aux = (Lis*) malloc(sizeof(Lis));
	
	aux->dados = cliente;
		
	if(listaVazia(lista)){	//Inserir no inicio, lista vazia
		aux->prox = NULL;
		aux->ant = NULL;
		*lista = aux;
		return 1;		
		
	}else{
		Lis *ante, *atual = *lista;
		while(atual != NULL && n<(posicao-1)){	
			n++;
			ante = atual;
			atual = atual->prox;
		}
		if(atual == *lista){
			aux->ant = NULL;
			(*lista)->ant=aux;
			aux->prox = (*lista);
			*lista = aux;
		}else{
			aux->prox = ante->prox;
			aux->ant = ante;
			ante->prox = aux;
			if(atual != NULL)
				atual->ant = aux;
		}
		
	}
		return 1;
}

//Remover Elemento
Cliente removerElemento(Lista* lista, int posicao){
	int n =0;
	if(lista == NULL)
		printf("Lista vazia\n");
	
	Lis *aux = *lista;
	while(aux !=NULL && (n<posicao-1)){
		n++;
		aux = aux->prox;
	}
	
	Cliente remover;
	strcpy(remover.nome, aux->dados.nome);
	strcpy(remover.cpf, aux->dados.cpf);
	if(aux ==NULL)
		printf("Não encontrado");
	if(aux->ant == NULL)
		*lista = aux->prox;
	else
		aux->ant->prox = aux->prox;
	if(aux->prox != NULL)
		aux->prox->ant = aux->ant;
	free(aux);
	return remover;
}

//Buscar Elemento na lista
int buscarPosicao(Lista* lista, char* CPF){
	int pos=0;
	if(listaVazia(lista)){
		printf("Lista vazia\n");
		return 0;
	}
	
	printf("O cpf buscado foi: %s\n", CPF);
	
	Lis* aux = *lista;
	while(aux != NULL){
		pos++;
		aux = aux->prox;
		if((strcmp(aux->dados.cpf, CPF) == 0)){
			printf("A posicao do cliente buscado foi: %d\n\n\n", pos+1);
			return 1;
		}
			
	}
	
} 

//FUNÇAO ADICIONAL
int listaVazia(Lista* lista){
	if(lista == NULL)
		return 1;
	if(*lista == NULL)
		return 1;
	return 0;
}

int tamanho(Lista* lista){
	if(lista == NULL)
		return 0;
	int cont = 0;
	Lis* aux = *lista;
	while(aux != NULL){		
		cont++;				
		aux = aux->prox;					
	}
	return cont;
}

void imprime(Lista* lista){
	int i;
	if(lista == NULL){
		printf("Lista invalida!\n\n\n");
		return;
	}
	Lis* aux = *lista;
	printf("\n\nLista\n");
	while(aux != NULL){
		printf("Nome: %s\n", aux->dados.nome);
		printf("Nome: %s\n", aux->dados.cpf);
		aux = aux->prox;
		printf("---------------------------\n");
	}
	
	
		int tam = tamanho(lista);
		printf("Quantidade de Clientes: %d\n\n", tam);	
		return;
	printf("Lista vazia!\n\n\n");
}

void imprimeCliente(Cliente cliente){
	printf("\n\nCliente--------------------\n");
	printf("Nome: %s\n", cliente.nome);
	printf("CPF: %s\n", cliente.cpf);
	printf("---------------------------\n");
	return;
}
	
