#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void imprimir_fila(Fila* fi);

int main(){

	struct cliente a[7] = {{"Gustavo","61101857366"},
						   {"Davi","1345798566"},
						   {"Kilvia","15468794855"},
						   {"Matheus","13456897544"},
						   {"Felipe","13598746822"},
						   {"Joel","13546897522"},
						   {"Hector","15487958699"}};

	Fila* fi = criar_fila();

	inserir_fila(fi, a[0]);
	inserir_fila(fi, a[1]);

	remove_inicio(fi);
	
	inserir_fila(fi, a[3]);

	imprimir_fila(fi);
	
	liberar_fila(fi);
	return 0;
}