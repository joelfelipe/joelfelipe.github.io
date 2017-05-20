#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct elemento{
	struct cliente dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Fila* criar_fila(){
	Fila* fi = (Fila*) malloc(sizeof(Fila));
	if(*fi != NULL)
		*fi = NULL;
	return fi;
}

void liberar_fila(Fila* fi){
	if(fi != NULL){
		Elem* cl;
	
		while(*fi != NULL){
			cl = *fi;
			*fi = (*fi)->prox;
			free(cl);
		}
		free(fi);
	}
}

int inserir_fila(Fila* fi, struct cliente cl){
	
	if(fi == NULL)
		return 0;
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL)
		return 0;
	no->dados = cl;
	no->prox = NULL;
	if(*fi == NULL){
		*fi = no;
	}else{
		Elem* aux;
		aux = *fi;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = no;
	}
	return 1;
}

int remove_inicio(Fila* fi){

	if(fi == NULL)
		return 0;
	if(*fi == NULL)
		return 0;
	
	Elem* no = *fi;
	*fi = no->prox;
	free(no);

	return 1;
}

void imprimir_fila(Fila* fi){
	if(fi == NULL)
		return;
	Elem* no = *fi;
	while(no != NULL){
		printf("Nome: %s\n", no->dados.nome);
		printf("CPF: %s\n", no->dados.cpf);
		printf("-------------------------\n");

		no = no->prox;
	}

}