#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"
void kruskal(Grafo *g)
{
	int tam=g->numArestas, i=0, cont=0;
	Aresta *VetOrd=(Aresta*) malloc(tam * sizeof(Aresta));
		VetOrd=criaHeap(g);
	Aresta *solucao;	
		solucao=(Aresta*) malloc(tam * sizeof(Aresta));
	int *conjunto=(int *) malloc(g->tamanho * sizeof(int));
		conjunto=makeset(g->tamanho);		
			while(tam>0)
			{
				if(findset(conjunto, VetOrd[i].chave_partida) != findset(conjunto, VetOrd[i].chave_adjacente))
				{
						solucao[i].chave_partida=VetOrd[i].chave_partida;
							solucao[i].chave_adjacente=VetOrd[i].chave_adjacente;
								solucao[i].peso=VetOrd[i].peso;
							uniao(conjunto, VetOrd[i].chave_partida,  VetOrd[i].chave_adjacente);	
							imprimeConj(g->tamanho, conjunto);
							cont++;
				}
				VetOrd=deleta(VetOrd, tam);
					tam--;
						i++;
			}
			printf("\n***\nAlgoritmo de KRUSKAL\n");
				for(i=0;i<cont;i++)
				{
					printf("[%d]-->%d-->[%d]-->", solucao[i].chave_partida, solucao[i].peso, solucao[i].chave_adjacente);
				}
				printf("FIM\n");
			printf("\n***\n");
}
