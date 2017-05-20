#ifndef PILHA_H
#define PILHA_H

struct cliente{
	char nome[30];
	char cpf[11];
};

typedef struct elemento* Fila;

Fila* criar_fila();

void liberar_fila(Fila* fi);

int inserir_fila(Fila* fi, struct cliente cl);

int remove_inicio(Fila* fi);

void imprimir_fila(Fila* fi);

#endif