#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#define MAX 100

typedef struct{
	char nome[MAX];
	char cpf[11];
}Cliente;

typedef struct lista* Lista; 


Lista* criarLista();

void deletarLista(Lista* lista);

int inserirElemento(Lista* lista, Cliente cliente, int posicao);

Cliente removerElemento(Lista* lista, int posicao);

int buscarPosicao(Lista* lista, char* CPF);

int listaVazia(Lista* lista);

int tamanho(Lista* lista);

void imprime(Lista* lista);

void imprimeCliente(Cliente cliente);