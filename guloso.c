#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"

int *retornaPeso(Grafo *g)
{
	int *vetor=(int*) malloc(sizeof(int));
		Nodo*aux=g->listanodos;
	int tam=0;
			while(aux->proximo!=NULL)
			{
				tam++;
				vetor=criaHeap(vetor, tam, aux->adjacente->peso);
					if(aux->adjacente->proximo!=NULL)
					{
						Aresta*aux2=aux->adjacente->proximo;
							while(aux2!=NULL)
							{
								tam++;
								vetor=criaHeap(vetor, tam, aux2->peso);
								aux2=aux2->proximo;
							}
					}
				aux=aux->proximo;	
			}
return vetor;
}

int retornaAresta(Grafo *g, int *vet, int *vetor)
{
		Nodo*aux=g->listanodos;
		//	int *vetor=(int *) malloc(sizeof(int));
			//int *vetorVar=(int *) malloc(sizeof(int));
				int i=0, j=0, entre=0, cont, contido=0, a, b;
				for(cont=0;cont<g->tamanho;cont++)
				{
					while(aux->proximo !=NULL)
					{
						if(vet[j] == aux->adjacente->peso)
						{
							contido=pertence(vetor, i, aux->adjacente->chave_partida, aux->adjacente->chave_adjacente);
							if(contido == 0)
							{
							vetor[i]=aux->adjacente->chave_partida;
							i++;
							vetor[i]=aux->adjacente->chave_adjacente;
							i++;
							j++;
							}
						}
							if(aux->adjacente->proximo!=NULL)
							{
								Aresta*aux2=aux->adjacente->proximo;
									contido=pertence(vetor, i, aux->adjacente->chave_partida, aux->adjacente->chave_adjacente);
									if(contido==0)
									{
										while(aux2!=NULL)
										{
											if(vet[j]==aux2->peso)
											{
												vetor[i]=aux2->chave_partida;
												i++;
												vetor[i]=aux2->chave_adjacente;
												i++;
												j++;
											}
											aux2=aux2->proximo;
										}
									}
							}	
						aux=aux->proximo;	
					}
				aux=g->listanodos;
				}
	return i;
//		return vetor;
}

int pertence(int *vet, int qnt, int u, int v)
{
	int i;
		for(i=0;i<qnt;i++)
		{
			if(vet[i]==u && vet[i+1]==v)
			{
				return 1;
			}
		}
		return 0;
}

int resultado(int *vet, int posicao, int qnt)
{
	int i, n=0;
		for(i=0;i<qnt;i++)
		{
			if(vet[i]==vet[posicao])
			{
				return vet[i];
				n++;
			}
		}
		if(n!=0)
		{
			printf("Nao encontrou\n");
			return 0;
		}
}



void kruskal(Grafo *g)
{
	//int u=0, v=0, peso=0, i=0, x, y, tam, posicao=0,posicao2=0, posicaoP=0, qnt=0;
		//int *vetArestas=(int *) malloc(sizeof(int));
			//int*solucao=(int*)malloc(sizeof(int));
				//int*vetPesos=(int *) malloc(sizeof(int));
					//int*vet=(int *) malloc(sizeof(int));
						//vetArestas=makeset(g->tamanho);
						//vetPesos=retornaPeso(g);
						//tam=retornaAresta(g, vetPesos, vet);
				//while(qnt!=tam)
				//{
					//u=resultado(vet, posicao, tam);
					//posicao2=posicao+1;
					//v=resultado(vet, posicao2, tam);
					//peso=resultado(vetPesos,posicaoP, g->tamanho);
							//x=findset(vetArestas, u);
								//y=findset(vetArestas, v);
						//if(x!=y)
						//{
					////		printf("entrei\n");
								//solucao[i]=u;
								//i++;
								//solucao[i]=v;
								//i++;
						//uniao(vetArestas,u, v); 
					////	imprimeConj(g->tamanho, vetArestas);
						//}
					//posicao=posicao+2;
					//posicaoP++;
					//qnt=qnt+2;
		//}
		//printf("-->Solucao do algoritmo KRUSKAL<--\n");
		//imprimeConj(i, solucao);
}

void prim(Grafo *g)
{
	
	
}
