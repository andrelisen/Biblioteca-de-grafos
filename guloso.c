#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> //biblioteca que contem o infinito
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"
void kruskal(Grafo *g) //ALGORITMO ALTERNATIVO 
{
	int i=0, cont=0, qnt=0, tam=g->numArestas, tam2=g->tamanho, x=0, y=0;
		Aresta *solucao;	
			solucao=(Aresta*) malloc(tam * sizeof(Aresta));
		int *conjunto=(int *) malloc(tam2 * sizeof(int));
			conjunto=makeset(tam2);		
		Aresta *VetOrd=(Aresta*) malloc(tam * sizeof(Aresta));
			Nodo*aux=g->listanodos;
				while(aux!=NULL) //percorro o Grafo para inserir as arestas TODAS
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
			percorre(VetOrd, qnt); //Faço a ordenação do vetor do tipo aresta com os PESOS em ordem crescente --> menor > maior
				while(qnt>0) //enquanto a heap estiver com elementos
				{
					x=findset(conjunto, VetOrd[0].chave_partida);
						y=findset(conjunto, VetOrd[0].chave_adjacente);
					//if(findset(conjunto, VetOrd[0].chave_partida) != findset(conjunto, VetOrd[0].chave_adjacente)) //Verifica se já não está na solução
					if(x!=y)
					{
							solucao[cont].chave_partida=VetOrd[0].chave_partida;
								solucao[cont].chave_adjacente=VetOrd[0].chave_adjacente;
									solucao[cont].peso=VetOrd[0].peso;
								conjunto=uniao(conjunto, x, y);	
					//	conjunto=uniao(conjunto, VetOrd[0].chave_partida, VetOrd[0].chave_adjacente);
									cont++;
					}
					VetOrd=deleta(VetOrd, qnt);
						qnt=qnt-1;
				}
			printf("\n\t\t\t===Algoritmo de KRUSKAL===\n");
				printf("Resposta apresentada da seguinte maneira: ---->[CHAVE DE PARTIDA]--PESO DA ARESTA--[CHAVE ADJACENTE]\n");
					printf("\n");
					for(i=0;i<cont;i++)
					{
						printf("[%d]---%d---[%d]---->", solucao[i].chave_partida, solucao[i].peso, solucao[i].chave_adjacente);
					}
					printf("FIM\n");
				printf("***\n");
}

void prim(Grafo *g) //ALGORITMO ALTERNATIVO 
{
	int tam=g->numArestas, prioridade=0, i=0, qnt=0, entrou=0, cont=0, x=0, y=0, opc=0;
		Aresta *solucao;	
			solucao=(Aresta*) malloc(tam * sizeof(Aresta));
		int *conjunto=(int *) malloc(g->tamanho * sizeof(int));
			conjunto=makeset(g->tamanho);
		printf("De qual nodo deseja iniciar? ");
			scanf("%d", &prioridade);
		Aresta *VetPrior=(Aresta*) malloc(tam * sizeof(Aresta));
					Nodo *no=g->listanodos; 			
						while(no!=NULL) //Utilizando somente os adjacentes do nodo inicial
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
										VetPrior=deleta(VetPrior, qnt);
												qnt=qnt-1;
								x=findset(conjunto, temporaria[0].chave_partida);
									y=findset(conjunto, temporaria[0].chave_adjacente);
							//	if(findset(conjunto, temporaria[0].chave_partida) != findset(conjunto, temporaria[0].chave_adjacente))
								if(x != y)
								{
						//			printf("Valores de findset=%d, %d\n", findset(conjunto, temporaria[0].chave_partida), findset(conjunto, temporaria[0].chave_adjacente));
									solucao[cont].chave_partida=temporaria[0].chave_partida;
										solucao[cont].chave_adjacente=temporaria[0].chave_adjacente;
											solucao[cont].peso=temporaria[0].peso;
												cont++;
								conjunto =	uniao(conjunto, x, y); //ASSIM FUNCIONA
							//	conjunto=uniao(conjunto, temporaria[0].chave_partida, temporaria[0].chave_adjacente); //ENGRAÇADO QUE ASSIM NÃO FUNCIONA
										prioridade=temporaria[0].chave_adjacente;
													entrou=1;
								//	printf("\n===\nValores=%d, %d=%d\n", temporaria[0].chave_partida, temporaria[0].chave_adjacente, temporaria[0].peso);
								}
								else
								{
							//	VetPrior=deleta(VetPrior, qnt);
							//		qnt=qnt-1;
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
									}
				}			
			do
			{
				printf("\n\t\t\t=== Menu para impressao do algoritmo de PRIM ===\n");
					printf("1-SAIR\n2-Mostrar caminho simples\n3-Caminho através dos pesos\n4-Caminho com arestas completas\nOpcao:");
						scanf("%d", &opc);
							switch(opc)
							{
								case 2:
										printf("\t\t\t---CAMINHO---\n");
											printf("%d->", solucao[0].chave_partida);
												for(i=0;i<cont;i++)
												{
												//printf("[%d]-->%d-->[%d]..", solucao[i].chave_partida,  solucao[i].peso, solucao[i].chave_adjacente);
													printf("%d->", solucao[i].chave_adjacente);
												}
														printf("FIM\n***\n");
								break;
								case 3:
										printf("\t\t\t---CAMINHO POR PESOS---\n");
											for(i=0;i<cont;i++)
											{
											printf("(%d)-->", solucao[i].peso);
											}
												printf("FIM\n***\n");
								break;
								case 4:
										printf("\t\t\t---CAMINHO COM ARESTA COMPLETA---\n");
											for(i=0;i<cont;i++)
											{
											printf("[%d]--%d--[%d]---->", solucao[i].chave_partida,  solucao[i].peso, solucao[i].chave_adjacente);
											}
												printf("FIM\n***\n");
								break;
							}
			}while(opc!=1);
}

void dijkstra(Grafo *g) //ALGORITMO CLÁSSICO
{
	int tam=g->tamanho, tam2=g->numArestas, i=0, qnt=0, prioridade=0, cont=0, entrei=0, u=0, v=0, peso=0, total=0, opc=0;
		int *distancia=(int*) malloc(tam * sizeof(int));
			int *antecessor=(int*) malloc(tam * sizeof(int));
		//distancia=INT_MAX; ---> infinito
		for(i=0;i<tam;i++)
		{
			distancia[i]=INT_MAX;
				antecessor[i]=-1; //inicializa todos com nenhum antecessor 
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
					while(no->proximo!=NULL)   //adjacente do nodo inicial
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
											prioridade = v; //atualiza a prioridade para que tenha novos adjacentes
												entrei=1;
													total=total + distancia[v];
							}
								else
								{
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
				do
				{		
				printf("\t\t\t=== Menu para a impressão do Algoritmo de DIJKSTRA ===\n");	
					printf("1-SAIR\n2-Caminho simples\n3-Caminho atraves das distancias\n4-Caminho com arestas completas\nOpcao:");
						scanf("%d", &opc);
						switch(opc)
						{
						case 2:
							printf("\t\t\t--Caminho--\n");
								for(i=0;i<cont;i++)
								{
								printf("%d-->", solucao[i]);
								}
									printf("FIM\n***\n");
						break;
						case 3:
								printf("\n\t\t\t--Distancia--\n");
									for(i=0;i<cont;i++)
									{
									printf("[%d]-->", distancia[solucao[i]]);
									}
									printf("FIM\n***\n");
											printf("Total das distancias e=%d\n", total);
						break;
						case 4:					
								printf("\t\t\t--CAMINHO COM ARESTA COMPLETA--\n");
									for(i=0;i<cont;i++)
									{
										printf("[%d]---%d---[%d]---->", antecessor[solucao[i]], distancia[solucao[i]], solucao[i]);
									}
									printf("FIM\n***\n");
						break;
					}
			}while(opc!=1);
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
