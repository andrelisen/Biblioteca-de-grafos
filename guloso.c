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
		VetOrd=alocaHeap(g);
	Aresta *solucao;	
		solucao=(Aresta*) malloc(tam * sizeof(Aresta));
	int *conjunto=(int *) malloc(g->tamanho * sizeof(int));
		conjunto=makeset(g->tamanho);		
			while(tam>0)
			{
				if(findset(conjunto, VetOrd[0].chave_partida) != findset(conjunto, VetOrd[0].chave_adjacente))
				{
						solucao[i].chave_partida=VetOrd[0].chave_partida;
							solucao[i].chave_adjacente=VetOrd[0].chave_adjacente;
								solucao[i].peso=VetOrd[0].peso;
							uniao(conjunto, VetOrd[0].chave_partida,  VetOrd[0].chave_adjacente);	
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
			free(solucao);
				free(conjunto);
					free(VetOrd);
}

void prim(Grafo *g)
{
	int i=0, cont=0, prioridade=0, tam=g->tamanho, u=0, v=0, peso=0;
		printf("De qual nodo deseja iniciar? ");
			scanf("%d", &prioridade);
				tam=tam-1;
		Aresta *VetPrior=(Aresta*) malloc(tam * sizeof(Aresta));
			VetPrior=heapPrior(g, prioridade, VetPrior); //adiciona apenas os adjacentes ao nodo escolhido
		Aresta *solucao;	
			solucao=(Aresta*) malloc(g->numArestas * sizeof(Aresta));
		int *conjunto=(int *) malloc(g->tamanho * sizeof(int));
			conjunto=makeset(g->tamanho);
				while(tam>0)
				{
						u=VetPrior[0].chave_partida;
							v=VetPrior[0].chave_adjacente;
								peso=VetPrior[0].peso;
							VetPrior=deleta(VetPrior, tam);
								tam--;
							if(findset(conjunto, u) != findset(conjunto,v))
							{
										solucao[cont].chave_partida=u;
											solucao[cont].chave_adjacente=v;
												solucao[cont].peso=peso;
													cont++;
										uniao(conjunto, u, v);
											VetPrior=heapPrior(g, v, VetPrior);	
												tam++;
							imprimeConj( g->tamanho, conjunto); 
							}
				}
				printf("\n***\nAlgoritmo de PRIM\n***\n");
					for(i=0;i<cont;i++)
					{
						printf("[%d]-->%d-->[%d]--", solucao[i].chave_partida, solucao[i].chave_adjacente, solucao[i].peso);
					}
						printf("FIM\n");
}
