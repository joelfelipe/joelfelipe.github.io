#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct elemento{
	struct cliente dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Pilha* criar_pilha(){
	Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
	if(pi !=NULL){
		*pi = NULL;
	}
	return pi;
}

void liberar_pilha(Pilha* pi){
	if(pi != NULL){
		Elem* cl;
		while(*pi != NULL){
			cl = *pi;
			*pi = (*pi)->prox;
			free(cl);
		}
		free(pi);
	}
}

int inserir_final(Pilha* pi, struct cliente cl){
	if(pi == NULL)
		return 0;
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL)
		return 0;
	no->dados = cl;
	no->prox = NULL;
	if(*pi == NULL){
		*pi = no;
	}else{
		Elem* aux;
		aux = *pi;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
	}
	return 1;
}
/*
int inserir_posicao(Lista* li, struct cliente cl, int index){
	if(li == NULL)
		return 0;
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL)
		return 0;

	no->dados = cl;
	no->prox = NULL;

	
	if(*li == NULL){
		*li = no;
	}else{
		Elem* aux, *novo;
		aux = *li;
		int cont = 0;
		while(cont < index-1){
			aux = aux->prox;
			cont++;
		}

		//aux->prox = no;
		printf("teste 1\n");
		no->prox = aux->prox;
		aux->prox = no;

		printf("teste 2\n");
		// while(no->prox == NULL){
		// 	printf("teste");
		// 	no->prox = aux->prox->prox;
		// }
		//no->prox = NULL;
	}

	return 1;
}
*/

int remover_final(Pilha* pi){

	if(pi == NULL)
        return 0;
    if((*pi) == NULL)//lista vazia
        return 0;

    Elem *ant, *no = *pi;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    
    if(no == (*pi))//remover o primeiro se a lista tiver um elemento
        *pi = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;

}

void print_pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("Nome: %s\n",no->dados.nome);
        printf("CPF: %s\n",no->dados.cpf);
        printf("-------------------------------\n");

        no = no->prox;
    }
}
