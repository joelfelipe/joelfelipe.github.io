#ifndef PILHA_H
#define PILHA_H



struct cliente{
	char nome[30];
	char cpf[12];
};

typedef struct elemento* Pilha;

Pilha* criar_pilha();

void liberar_pilha(Pilha* pi);

int inserir_final(Pilha* pi, struct cliente cl);

void print_pilha(Pilha* pi);

int remover_final(Pilha* pi);

//int inserir_posicao(Pilha* pi, struct cliente cl, int index);

//void inserirPosicao(Lista* li, struct cliente cl, int index);

#endif