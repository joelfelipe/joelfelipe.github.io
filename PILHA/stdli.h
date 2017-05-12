#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 100

typedef struct {
	char nome[30];
	char cpf[11];
}cliente;

typedef struct {
	cliente clientes[MAX];
	int qtd;
}Pilha;

//cria pilha
Pilha* criapilha();
//insere na ultima posicao da pilha
int inserircliente(Pilha* pilha, cliente cliente);
//remove cliente na ultima posição e retorna cliente
cliente removecliente(Pilha* pilha);
//deleta a pilha
void deletar(Pilha* pilha);
//imprime cliente removido
void imprimecliente(cliente cliente);
//imprime toda a pilha
void imprime(Pilha* pilha);

