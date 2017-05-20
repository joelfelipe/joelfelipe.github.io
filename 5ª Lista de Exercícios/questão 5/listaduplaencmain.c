#include "lista.h"

int main(){
	
	//Cliente cliente = {"Pessoa1", "000000001"};
		
	
	Cliente cliente[6] ={
		{"Pessoa1", "000000001"},
		{"Pessoa2", "000000002"},
		{"Pessoa3", "000000003"},
		{"Pessoa4", "000000004"},
		{"Pessoa5", "000000005"},
		{"Pessoa6", "000000006"}};
		
	Lista* lista = criarLista();
	imprime(lista);
		
	printf("Inserindo 1 cliente posicao 1\n");
	inserirElemento(lista, cliente[0], 1);	
	imprime(lista);
		
	printf("Inserindo 3 clientes");
	int i;
	for(i=1; i<4; i++){
		inserirElemento(lista, cliente[i], (i+1));
	}
	imprime(lista);
	
	printf("Inserindo 1 cliente na posicao 3");
	inserirElemento(lista, cliente[4], 3);
	imprime(lista);
	
	printf("Remover cliente da posicao 5\n");
	imprimeCliente(removerElemento(lista, 5));
	imprime(lista);
	
	printf("Buscar um cliente\n");
	buscarPosicao(lista, "000000003");
	
	printf("Deletar a lista\n");
	deletarLista(lista);
	imprime(lista);
	
	return 0;
}