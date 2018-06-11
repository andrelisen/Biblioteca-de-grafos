#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"

int main(void)
{
	int x, y, val, i=0, qnt=0;
	Grafo *g;
					Aresta*vetor=(Aresta *) malloc( g->numArestas * sizeof(Aresta));
	do{
		printf("\n------\n");
		printf("MENU\n");
		printf("0-Sair\n1-Criar grafo\n2-Imprimir\n3-Busca DFS\n4-Busca BFS\n5-Kruskal\n6-Prim\n7-Dijkstra\n->Opcao:");
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
					case 6:
							prim(g);
					break;
					case 7:
							dijkstra(g);
					break;
			
			}
	}while(x!=0);	
}
