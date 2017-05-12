#include "stdli.h"

int main(){
	//setando um vetor de clientes para teste
	
	cliente cliente[10] = {
		{"teste 1","123456789"},
        {"teste 2","123456789"},
        {"teste 3","123456789"},
        {"teste 4","123456789"},
        {"teste 5","123456789"},
		{"teste 6","123456789"},
        {"teste 7","123456789"},
        {"teste 8","123456789"},
        {"teste 9","123456789"},
        {"teste 10","123456789"}
	};
	
	printf("\nCRIANDO PILHA VAZIA\n");//criando pilha vazia
	Pilha* pilha = criapilha();
	//imprimindo a pilha vazia
	imprime(pilha);
	
	
	printf("\nINSERINDO CLIENTES\n");//inserindo clientes
	int i;
    for(i=0; i < 10; i++){
		inserircliente(pilha, cliente[i]);
    }
	//imprimindo a pilha depois de clientes inseridos
	imprime(pilha);
	
	
	printf("REMOVENDO CLIENTE DA ULTIMA POSICAO\n");//removendo cliente
	//funçao recebendo cliente retornado da função remover e imprimindo
	printf("O CLIENTE REMOVIDO FOI:\n");//removendo cliente
	imprimecliente(removecliente(pilha));
	//imprimindo a pilha depois da remoção
	imprime(pilha);
	
	
	printf("\nDELETANDO A PILHA COMPLETA\n");//Deletando Pilha
	deletar(pilha);
	//imprimindo pilha depois de deletada
	imprime(pilha);
	
	//comando para compilar no GCC
	//gcc pilha.c stdli.h main.c -o prog
	return 0;
}