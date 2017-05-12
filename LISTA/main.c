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
	
	printf("\nCRIANDO LISTA VAZIA\n");//criando lista vazia
	Lista* lista = crialista();
	//imprimindo a lista vazia
	imprime(lista);
	
	
	printf("\nINSERINDO CLIENTES\n");//inserindo clientes
	int i;
    for(i=0; i < 10; i++){
		inserircliente(lista, cliente[i], (i + 1));
    }
	//imprimindo a lista depois de clientes inseridos
	imprime(lista);
	
	
	printf("REMOVENDO CLIENTE DA POSICAO 5\n");//removendo o 5º cliente
	//funçao recebendo cliente retornado da função remover e imprimindo
	printf("O CLIENTE REMOVIDO FOI:\n");//removendo o 5º cliente
	imprimecliente(removecliente(lista, 5));
	//imprimindo a lista depois da remoção
	imprime(lista);
	
	
	printf("\nBUSCANDO O INDICE DE UM ELEMENTO\n");
	//buscando indice de cliente, retorna um inteiro com o valor do índice
	printf("\nBUSCANDO O INDICE DE UM ELEMENTO EXISTENTE\n");
	printf("\nCLIENTE QUE ESTÁ SENDO BUSCADO E:\n");
	imprimecliente(cliente[5]);
	//buscando cliente existente
	buscar(lista, cliente[5]);
	//buscando inexistente
	printf("\nBUSCANDO O INDICE DE UM ELEMENTO INEXISTENTE\n");
	printf("\nCLIENTE QUE ESTÁ SENDO BUSCADO E:\n");
	imprimecliente(cliente[4]);
	buscar(lista, cliente[4]);
	imprime(lista);
	
	
	printf("\nDELETANDO A LISTA COMPLETA\n");//Deletando Lista
	deletar(lista);
	//imprimindo lista depois de deletada
	imprime(lista);
	
	//comando para compilar no GCC
	//gcc lista.c stdli.h main.c -o prog
	return 0;
}