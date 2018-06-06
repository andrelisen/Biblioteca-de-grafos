#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"

Aresta *retornaHeap(Grafo *g)
{
		Nodo*aux=g->listanodos;
		Aresta *nova=(Aresta*) malloc(sizeof(Aresta));
		nova->proximo=NULL;
		int tam=0;
			while(aux!=NULL)
			{
				criaHeap(nova ,aux->chave, aux->adjacente->chave_adjacente, aux->adjacente->peso);
					if(aux->adjacente->proximo!=NULL)
					{
						Aresta*aux2=aux->adjacente->proximo;
							while(aux2!=NULL)
							{
								criaHeap(nova, aux2->chave_partida, aux2->chave_adjacente, aux2->peso);
								aux2=aux2->proximo;
							}
					}
				aux=aux->proximo;	
			}
			
return nova;
}

int tamanhoHeap(Aresta *vetor)
{
	Aresta *aux=vetor->proximo;
	int tam=0;
		while(aux!=NULL)
		{
			tam++;
			aux=aux->proximo;
		}
return tam;
}

//void kruskal(Grafo *g)
//{
	//int tam=g->tamanho;
	//int *vet=(int *) malloc(tam * sizeof(int));
	//vet=makeset(tam);

//}

void kruskal(Grafo *g)
{
	Aresta *heap=retornaHeap(g);
	int tamHeap=tamanhoHeap(heap);
			Aresta *tmp;
				tmp = heap->proximo;
					while( tmp != NULL)
					{
					printf("%d\t", tmp->chave_partida);
					printf("%d\t", tmp->chave_adjacente);
					printf("%d\t", tmp->peso);
					printf("\n");
					tmp = tmp->proximo;
					}
				printf("---\n"); printf("Tamanho da heap é:%d\n", tamHeap); printf("---\n");
}
