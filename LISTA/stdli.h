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
}Lista;


Lista* crialista();

//imprime cliente removido
void imprimecliente(cliente cliente);
//deleta a lista
void deletar(Lista* lista);
//imprime toda a lista
void imprime(Lista* lista);
//buscar cliente
int buscar(Lista* lista, cliente cliente);
//remove qualquer cliente na posição desejada retorna cliente
cliente removecliente(Lista* lista, int index);
//insere numa determinada posicao da lista
int inserircliente(Lista* lista, cliente cliente, int index);