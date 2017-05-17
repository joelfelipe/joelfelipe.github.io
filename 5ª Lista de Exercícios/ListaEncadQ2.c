#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
	char nome[30];
	int cpf;
}cliente;

struct Node{
	cliente cliente;
	struct Node *prox;
}; 
typedef struct Node node;

int tam;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
void insere (node *LISTA);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);
node *retira(node *LISTA);


int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(LISTA);//Inicia Lista vazia
	int opt;
	
	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);

	free(LISTA);
	return 0;
	}
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
	tam=1;
}

int menu(void)
{
	int opt;
	
	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Inserir Elemento\n");
	printf("2. Remover Elemento\n");
	printf("3. Buscar a Posicao do Elemento\n");//falta fazer
	printf("4. Exibir lista\n");
	printf("5. Deletar lista\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(node *LISTA, int op)
{
	node *tmp;
	switch(op){
		case 0:
			libera(LISTA);
			break;
			
		case 1:
			insere(LISTA);
			break;
		
		case 2:
			tmp= retira(LISTA);
			printf("Retirado: %s\n\n", tmp->cliente.nome);
			break;
		
		case 3:
			//buscar posição do elemento
			buscar(LISTA);
			break;		
			
		case 4:
			exibe(LISTA);
			break;
			
		case 5:
			printf("\n\nLista deletada!\n\n");
			libera(LISTA);
			inicia(LISTA);
			break;
		
		default:
			printf("Comando invalido\n\n");
	}
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

node *aloca()
{	
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		printf("Nome do Cliente: ");
		scanf("%s", &novo->cliente.nome);
		fflush(stdin);
		printf("CPF do Cliente: ");
		scanf("%d", &novo->cliente.cpf);
		fflush(stdin);
		return novo;
	}
}

void exibe(node *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	int qtd = 1;
	while( tmp != NULL){
		printf("\nCliente %d ", qtd);
		printf("\nNome: %s ", tmp->cliente.nome);
		printf("\nCPF: %d", tmp->cliente.cpf);
		printf("\n\n");
		tmp = tmp->prox;
		++qtd;
	}
	printf("\n        ");
	printf("\n\n");
}

void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;
		
		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

int buscar(node *LISTA)
{	
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return 0;
	}
	int pos,
		count;
	printf("Qual o CPF do cliente que deseja buscar? ");
	scanf("%d", &pos);
	node *atual = LISTA->prox,
		 *anterior = LISTA; 
	for(count=1 ; count < tam ; count++){
			if(pos == atual->cliente.cpf){
				printf("\n\nO cliente est na posicao %d\n\n", count);
				return 1;
			}
			anterior=atual;
			atual=atual->prox;
	}
	return 0;
}

void insere(node *LISTA)
{
	int pos,
		count;
	printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
	scanf("%d", &pos);
	
	if(pos>0 && pos <= tam){
		if(pos==1)
			insereInicio(LISTA);
		else{
			node *atual = LISTA->prox,
				 *anterior=LISTA; 
			node *novo=aloca();
				 
			for(count=1 ; count < pos ; count++){
					anterior=atual;
					atual=atual->prox;
			}
			anterior->prox=novo;
			novo->prox = atual;
			tam++;
		}
			
	}else
		printf("Elemento invalido\n\n");		
}

node *retiraInicio(node *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista ja esta vazia\n");
		return NULL;
	}else{
		node *tmp = LISTA->prox;
		LISTA->prox = tmp->prox;
		tam--;
		return tmp;
	}
				
}

node *retiraFim(node *LISTA)
{
	if(LISTA->prox == NULL){
		printf("Lista ja vazia\n\n");
		return NULL;
	}else{
		node *ultimo = LISTA->prox,
			 *penultimo = LISTA;
			 
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
			 
		penultimo->prox = NULL;
		tam--;
		return ultimo;		
	}
}

node *retira(node *LISTA)
{
	int opt,
		count;
	printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", (tam-1));
	scanf("%d", &opt);
	
	if(opt>0 && opt <= tam){
		if(opt==1)
			return retiraInicio(LISTA);
		else{
			node *atual = LISTA->prox,
				 *anterior=LISTA; 
				 
			for(count=1 ; count < opt ; count++){
				anterior=atual;
				atual=atual->prox;
			}
			
		anterior->prox=atual->prox;
		tam--;
		return atual;
		}
			
	}else{
		printf("Elemento invalido\n\n");
		return NULL;
	}
}

void insereFim(node *LISTA)
{
	node *novo=aloca();
	novo->prox = NULL;
	
	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
	tam++;
}

void insereInicio(node *LISTA)
{
	node *novo=aloca();	
	node *oldHead = LISTA->prox;
	
	LISTA->prox = novo;
	novo->prox = oldHead;
	
	tam++;
}