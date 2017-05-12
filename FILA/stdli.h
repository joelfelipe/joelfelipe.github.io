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
}Fila;


Fila* criafila();

//imprime cliente removido
void imprimecliente(cliente cliente);
//deleta a fila
void deletar(Fila* fila);
//imprime toda a fila
void imprime(Fila* fila);
//remove qualquer cliente na posição desejada retorna cliente
cliente removecliente(Fila* fila);
//insere numa determinada posicao da fila
int inserircliente(Fila* fila, cliente cliente);