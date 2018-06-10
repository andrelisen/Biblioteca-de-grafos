#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"
void kruskal(Grafo *g)
{
	int i=0, cont=0, qnt=0, tam=g->numArestas, tam2=g->tamanho;
		Aresta *solucao;	
			solucao=(Aresta*) malloc(tam * sizeof(Aresta));
		int *conjunto=(int *) malloc(tam2 * sizeof(int));
			conjunto=makeset(tam2);		
		Aresta *VetOrd=(Aresta*) malloc(tam * sizeof(Aresta));
			Nodo*aux=g->listanodos;
				while(aux!=NULL)
				{
					if(aux->adjacente!=NULL)
					{
					qnt=qnt+1;
						VetOrd=criaHeap(VetOrd, aux->adjacente->chave_partida, aux->adjacente->chave_adjacente, aux->adjacente->peso, qnt, tam);
						if(aux->adjacente->proximo!=NULL)
						{
							Aresta*aux2=aux->adjacente->proximo;
								while(aux2!=NULL)
								{
								qnt=qnt+1;
									VetOrd=criaHeap(VetOrd, aux2->chave_partida, aux2->chave_adjacente, aux2->peso, qnt, tam);
								aux2=aux2->proximo;
								}
						}	
					}
					aux=aux->proximo;
				}	
		for(i=0;i<qnt;i++)
			{
				printf("%d,%d=%d\n", VetOrd[i].chave_partida, VetOrd[i].chave_adjacente, VetOrd[i].peso);
			}
			percorre(VetOrd, qnt);
			printf("percorreu\n");
			for(i=0;i<qnt;i++)
			{
				printf("%d,%d=%d\n", VetOrd[i].chave_partida, VetOrd[i].chave_adjacente, VetOrd[i].peso);
			}
				while(qnt>0)
				{
				//	printf("WHILE:%d,%d=%d\n", VetOrd[0].chave_partida, VetOrd[0].chave_adjacente, VetOrd[0].peso);
					if(findset(conjunto, VetOrd[0].chave_partida) != findset(conjunto, VetOrd[0].chave_adjacente))
					{
							solucao[cont].chave_partida=VetOrd[0].chave_partida;
								solucao[cont].chave_adjacente=VetOrd[0].chave_adjacente;
									solucao[cont].peso=VetOrd[0].peso;
					//		printf("conj antes\n");
					//		imprimeConj(tam2, conjunto);
								uniao(conjunto, VetOrd[0].chave_partida,  VetOrd[0].chave_adjacente);	
					//		printf("conj depois\n");
									cont++;
					}
					VetOrd=deleta(VetOrd, qnt);
						qnt=qnt-1;
				}
				printf("\n***\nAlgoritmo de KRUSKAL\n");
					for(i=0;i<cont;i++)
					{
						printf("[%d]-->%d-->[%d]-->", solucao[i].chave_partida, solucao[i].peso, solucao[i].chave_adjacente);
					}
					printf("FIM\n");
				printf("\n***\n");
}

void prim(Grafo *g)
{
	int tam=g->numArestas, prioridade=0, i=0, qnt=0, entrou=0, cont=0;
		Aresta *solucao;	
			solucao=(Aresta*) malloc(tam * sizeof(Aresta));
		int *conjunto=(int *) malloc(g->tamanho * sizeof(int));
			conjunto=makeset(g->tamanho);
		printf("De qual nodo deseja iniciar? ");
			scanf("%d", &prioridade);
		Aresta *VetPrior=(Aresta*) malloc(tam * sizeof(Aresta));
					Nodo *no=g->listanodos; //quando tem prioridade e eu preciso inserir os adjacentes da heap nele!
						while(no!=NULL)
						{
							if(no->adjacente!=NULL)
							{
								if(no->adjacente->chave_partida == prioridade)
								{
									qnt++; //numero de elementos que já foram inseridos na minha heap
										VetPrior=criaHeap(VetPrior, no->adjacente->chave_partida, no->adjacente->chave_adjacente, no->adjacente->peso, qnt, g->numArestas);
						//					i++;	
									if(no->adjacente->proximo!=NULL)
									{
									Aresta *no2=no->adjacente->proximo;
										while(no2!=NULL)
										{
										qnt++;
											VetPrior=criaHeap(VetPrior, no2->chave_partida, no2->chave_adjacente, no2->peso, qnt, g->numArestas);
									//			i++;
										no2=no2->proximo;
										}
									}
								}
							}
						no=no->proximo;
						}
						percorre(VetPrior, qnt);		
				while(qnt>0)
				{
					if(findset(conjunto, VetPrior[0].chave_partida) != findset(conjunto, VetPrior[0].chave_adjacente))
							{
								solucao[cont].chave_partida=VetPrior[0].chave_partida;
									solucao[cont].chave_adjacente=VetPrior[0].chave_adjacente;
										solucao[cont].peso=VetPrior[0].peso;
											cont++;
								uniao(conjunto, VetPrior[0].chave_partida, VetPrior[0].chave_adjacente);
									prioridade=VetPrior[0].chave_adjacente;
										VetPrior=deleta(VetPrior, qnt);
											qnt--;
											entrou=1;
							}
							else{
								VetPrior=deleta(VetPrior, qnt);
									qnt--;
									entrou=0;
							}
							if(entrou==1)
								{
							Nodo *no=g->listanodos; //quando tem prioridade e eu preciso inserir os adjacentes da heap nele!
								while(no->proximo!=NULL)
								{
									if(no->adjacente!=NULL)
									{
										if(no->adjacente->chave_partida == prioridade)
										{
										qnt++; //numero de elementos que já foram inseridos na minha heap
											VetPrior=criaHeap(VetPrior, no->adjacente->chave_partida, no->adjacente->chave_adjacente, no->adjacente->peso, qnt, g->numArestas);	
												i++;
											if(no->adjacente->proximo!=NULL) // se nao tem adj de nada adianta né!
											{
												Aresta *no2=no->adjacente->proximo;
												while(no2!=NULL)
												{
												qnt++;
													VetPrior=criaHeap(VetPrior, no2->chave_partida, no2->chave_adjacente, no2->peso, qnt, g->numArestas);
														i++;
												no2=no2->proximo;
												}
											}
										}
									}
									no=no->proximo;
								}
									percorre(VetPrior, qnt);
							}
					
				}
				printf("\n***\nAlgoritmo de PRIM\n***\n");
					for(i=0;i<cont;i++)
					{
						printf("[%d]-->%d-->[%d]-->", solucao[i].chave_partida,  solucao[i].peso, solucao[i].chave_adjacente);
					}
						printf("FIM\n");
}
