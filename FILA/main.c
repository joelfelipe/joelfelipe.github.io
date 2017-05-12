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
	
	printf("\nCRIANDO FILA VAZIA\n");//criando fila vazia
	Fila* fila = criafila();
	//imprimindo a fila vazia
	imprime(fila);
	
	
	printf("\nINSERINDO CLIENTES\n");//inserindo clientes
	int i;
    for(i=0; i < 10; i++){
		inserircliente(fila, cliente[i]);
    }
	//imprimindo a fila depois de clientes inseridos
	imprime(fila);
	
	
	printf("REMOVENDO CLIENTE DA PRIMEIRA POSICAO\n");//removendo cliente
	//funçao recebendo cliente retornado da função remover e imprimindo
	printf("O CLIENTE REMOVIDO FOI:\n");//removendo cliente
	imprimecliente(removecliente(fila));
	//imprimindo a fila depois da remoção
	imprime(fila);
	
	
	printf("\nDELETANDO A FILA COMPLETA\n");//Deletando Fila
	deletar(fila);
	//imprimindo fila depois de deletada
	imprime(fila);
	
	//comando para compilar no GCC
	//gcc fila.c stdli.h main.c -o prog
	return 0;
}