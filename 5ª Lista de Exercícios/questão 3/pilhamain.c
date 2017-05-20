#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//void imprime_lista(Lista* li);
// Lista* criar_lista();

int main(){

	struct cliente a[6] = {{"Andre","135975"},
							{"Gustavo","1468795"},
							{"João","13467985"},
							{"Ana","5975841"},
							{"Isabelly","34682467"},
							{"teste","asdadasd"}};
                       	   
	int i;
    Pilha *pi = criar_pilha();
    for(i=0; i<4; i++)
    	inserir_final(pi, a[i]);
	
	inserir_final(pi, a[4]);
	inserir_final(pi, a[5]);
	
	for(i=0; i<6; i++)
		remover_final(pi);
	
	//inserir_final(pi, a[3]);

	print_pilha(pi);
	liberar_pilha(pi);
	return 0;
}