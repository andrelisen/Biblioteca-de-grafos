#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"

int main(void)
{
	int x, y, val;
	Grafo *g;
	int *vet = (int*) malloc(sizeof(int)); // aloca só uma posição
	int *vet2 = (int*) malloc(sizeof(int));
	
	do{
		printf("\n------\n");
		printf("MENU\n");
		printf("0-Sair\n1-Criar grafo\n2-Imprimir\n3-Busca DFS\n4-Busca BFS\n5-Kruskal\n->Opcao:");
		scanf("%d", &x);
			switch (x){
					case 1:
							y=quantidade();
							g=cria(y);
							criaAresta(g);
					break;
					case 2:
							imprimeGrafo(g);
					break;
					case 3:
							buscadfs(g);
					break;
					case 4:
							buscabfs(g);
					break;			
					case 5:
						kruskal(g);
					break;
					//case 6:
					
				//	break;
				//	case 7:
					
				//	break;
			
			}
	}while(x!=0);	
}
