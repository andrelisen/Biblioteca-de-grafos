#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> //biblioteca que contem o infinito
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
			percorre(VetOrd, qnt);
				while(qnt>0)
				{
					if(findset(conjunto, VetOrd[0].chave_partida) != findset(conjunto, VetOrd[0].chave_adjacente))
					{
							solucao[cont].chave_partida=VetOrd[0].chave_partida;
								solucao[cont].chave_adjacente=VetOrd[0].chave_adjacente;
									solucao[cont].peso=VetOrd[0].peso;
								uniao(conjunto, VetOrd[0].chave_partida,  VetOrd[0].chave_adjacente);	
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
									qnt=qnt+1; 
										VetPrior=criaHeap(VetPrior, no->adjacente->chave_partida, no->adjacente->chave_adjacente, no->adjacente->peso, qnt, g->numArestas);
									if(no->adjacente->proximo!=NULL)
									{
									Aresta *no2=no->adjacente->proximo;
										while(no2!=NULL)
										{
										qnt=qnt+1;
											VetPrior=criaHeap(VetPrior, no2->chave_partida, no2->chave_adjacente, no2->peso, qnt, g->numArestas);
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
								Aresta *temporaria=(Aresta*) malloc(1 * sizeof(Aresta));
									temporaria=raiz(VetPrior, qnt);
										printf("%d,%d=%d\n", temporaria[0].chave_partida, temporaria[0].chave_adjacente, temporaria[0].peso);
								if(findset(conjunto, VetPrior[0].chave_partida) != findset(conjunto, VetPrior[0].chave_adjacente))
								{
									solucao[cont].chave_partida=VetPrior[0].chave_partida;
										solucao[cont].chave_adjacente=VetPrior[0].chave_adjacente;
											solucao[cont].peso=VetPrior[0].peso;
												cont++;
									uniao(conjunto, VetPrior[0].chave_partida, VetPrior[0].chave_adjacente);
										prioridade=VetPrior[0].chave_adjacente;
											VetPrior=deleta(VetPrior, qnt);
												qnt=qnt-1;
													entrou=1;
								}
								else
								{
								VetPrior=deleta(VetPrior, qnt);
									qnt=qnt-1;
										entrou=0;
								}
									if(entrou==1)
									{
										Nodo *no=g->listanodos; 
											while(no->proximo!=NULL)
											{
												if(no->adjacente!=NULL)
												{
													if(no->adjacente->chave_partida == prioridade)
													{
													qnt=qnt+1; 
														VetPrior=criaHeap(VetPrior, no->adjacente->chave_partida, no->adjacente->chave_adjacente, no->adjacente->peso, qnt, g->numArestas);	
														if(no->adjacente->proximo!=NULL) // se nao tem adj de nada adianta né!
														{
														Aresta *no2=no->adjacente->proximo;
															while(no2!=NULL)
															{
															qnt=qnt+1;
																VetPrior=criaHeap(VetPrior, no2->chave_partida, no2->chave_adjacente, no2->peso, qnt, g->numArestas);
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

void dijkstra(Grafo *g)
{
	int tam=g->tamanho, tam2=g->numArestas, i=0, qnt=0, prioridade=0, cont=0, entrei=0, u=0, v=0, peso=0;
		int *distancia=(int*) malloc(tam * sizeof(int));
			int *antecessor=(int*) malloc(tam * sizeof(int));
		//distancia=INT_MAX/2; ---> infinito
		for(i=0;i<tam;i++)
		{
			distancia[i]=INT_MAX;
				antecessor[i]=-1; //inicializa todos com nenhum antecessor ou poderia colocar 0-->pensar
		}
		int *solucao;
			solucao=(int*) malloc(tam * sizeof(int));
				for(i=0;i<tam;i++)
				{
					solucao[i]=-1;//inicializando
				}
		Aresta *heap;
			heap=(Aresta*) malloc(tam2 * sizeof(Aresta));
				Nodo *no=g->listanodos; 
				printf("De qual nodo deseja iniciar o algoritmo?");
				scanf("%d", &prioridade);
					while(no->proximo!=NULL)
					{
						if(no->adjacente!=NULL)
						{
							if(no->adjacente->chave_partida == prioridade)
							{
								qnt=qnt+1; 
									heap=criaHeap(heap, no->adjacente->chave_partida, no->adjacente->chave_adjacente, no->adjacente->peso, qnt, g->numArestas);	
										if(no->adjacente->proximo!=NULL) // se nao tem adj de nada adianta né!
										{
										Aresta *no2=no->adjacente->proximo;
											while(no2!=NULL)
											{
												qnt=qnt+1;
													heap=criaHeap(heap, no2->chave_partida, no2->chave_adjacente, no2->peso, qnt, g->numArestas);
														no2=no2->proximo;
											}
										}
							}
						}
					no=no->proximo;
					}
						percorre(heap, qnt);
						distancia[prioridade]=0;
					while(qnt>0)
					{
					u=heap[0].chave_partida;
						v=heap[0].chave_adjacente;
							peso=heap[0].peso;
								heap=deleta(heap, qnt);
									qnt=qnt-1;
						if((verifica(solucao, cont, u)==0))
						{
							solucao[cont]=u;
								cont++;
						}
							if(verifica(solucao, cont, v) == 0 && distancia[v] > distancia[u] + peso)
							{
							solucao[cont]=v;
							cont++;
							antecessor[v] = u; //v=u
								distancia[v] = distancia[u] + peso;
								prioridade = v;
									entrei=1;
							}
							else{
								entrei=0;
							}
							if(entrei==1)
									{
										Nodo *no=g->listanodos; 
											while(no->proximo!=NULL)
											{
												if(no->adjacente!=NULL)
												{
													if(no->adjacente->chave_partida == prioridade)
													{
													qnt=qnt+1; 
														heap=criaHeap(heap, no->adjacente->chave_partida, no->adjacente->chave_adjacente, no->adjacente->peso, qnt, g->numArestas);	
														if(no->adjacente->proximo!=NULL) 
														{
														Aresta *no2=no->adjacente->proximo;
															while(no2!=NULL)
															{
															qnt=qnt+1;
																heap=criaHeap(heap, no2->chave_partida, no2->chave_adjacente, no2->peso, qnt, g->numArestas);
																	no2=no2->proximo;
															}
														}
													}
												}
											no=no->proximo;
											}
									percorre(heap, qnt);
									}
					}	
					printf("Algoritmo de DIJKSTRA\n");
			for(i=0;i<cont;i++)
			{
				printf("%d->", solucao[i]);
			}
			printf("FIM\n");
}

int verifica(int *vetor, int quantidade, int valor)
{
	int i, existe=0;
		for(i=0;i<quantidade;i++)
		{
			if(vetor[i]==valor)
			{
			existe++;
			}
		}
		if(existe!=0)
		{
		return 1;
		}
		else{
		return 0;
		}
}
