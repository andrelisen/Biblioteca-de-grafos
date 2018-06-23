#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"
//DFS

pilha *criapilha(void)
{
	pilha *novo=(pilha*)malloc(sizeof(pilha));
		novo->proximo=NULL;
	return novo;	
}

void push(pilha *pi, int valor)//coloca
{
			pilha *novo=(pilha *) malloc(sizeof(pilha));
			novo->valor=valor;
			novo->proximo=NULL;
				if(pi->proximo==NULL)
				{
					pi->proximo=novo;
				}
					else{ 
						pilha *tmp=pi->proximo;	
							while(tmp->proximo != NULL)
							{
							tmp = tmp->proximo;			
							}
								tmp->proximo = novo;	
						}	
}

void exibe(pilha *pi)
{
	pilha *percorre=pi->proximo;
			printf("--\n");
			while(percorre!=NULL)
			{
				printf("valordapilha=%d", percorre->valor);
				percorre=percorre->proximo;
			}
			printf("--\n");
}

int buscapilha(pilha *pi, int num)
{
	int cont=0;
	pilha *percorre=pi->proximo;
			while(percorre!=NULL)
			{
				if(percorre->valor == num)
				{
					cont ++;
				}
				percorre=percorre->proximo;
			}
				if(cont ==1)
				{
					return 1;//sim, esse elemento está na minha pilha
				}
					else{
						return 0;//elemento não está na pilha 
					}
}

int pop(pilha *pi)
{
				pilha *descobre=pi->proximo;
					pilha *nova=pi;//toda a minha pilha
						while(descobre->proximo!=NULL)
						{
							nova=descobre;
							descobre=descobre->proximo;
						}
							nova->proximo=NULL;
							return descobre->valor;
}

int vazia(pilha *pi)
{
	if(pi->proximo == NULL)
	{
		return 1;
	}
		else
		{
			return 0;
		}
}

//visita-se o vertice inicial V
//Um vértice não visitado W, adjacente a V é selecionado, iniciando umapesq em prof a apartir de W
//atinge um vert U tal que todos seus adj sejam visitados voltamos para o ultimo vertice adj n visitado e iniciamos a pesq de prof dele
void buscadfs(Grafo *g)
{
	int val;
	printf("De qual nodo deseja iniciar a procura?\n");
	scanf("%d", &val);
	setbuf(stdin, NULL);
	int i=0, y=0, j;
		pilha *nova=criapilha();
		push(nova, val);
		Nodo *aux=busca(g, val);
		int *vetorvisitado=(int *)malloc(sizeof(int));
				while((vazia(nova))!=1)
				{
					val=pop(nova);
						aux=busca(g, val);
							y=0;
					for(j=0;j<i;j++)
					{
						if(vetorvisitado[j]==val)
						{
							y++;
						}
					}
						if(y==0)
						{
							vetorvisitado[i]=val;
							i++;
							Aresta *no=aux->adjacente;
								while(no!=NULL)
								{
								push(nova, no->chave_adjacente);
									no=no->proximo;
								}			
						}
						//	Aresta *no=aux->adjacente;
						//		while(no!=NULL)
						//		{
						//		push(nova, no->chave_adjacente);
						//			no=no->proximo;
						//		}			
					//		val=pop(nova);
					//		aux=busca(g, val);
					//		y=0;
				}
						//impressão dos elementos em ordem de busca
						printf("\n>A ordem de busca DFS segue abaixo<\n");
							for(j=0;j<i;j++)
							{
								printf("%d\t", vetorvisitado[j]);
							}
}
 
//BFS
int filavazia(fila *f)
{
	if(f->inicio==NULL && f->fim==NULL)//se vazia retorna 1 
	{
		return 1;
	}
		else{
			return 0;
		}
}
 
fila *criafila(void)
{
	fila *novo=(fila*) malloc(sizeof(fila));
		novo->inicio=NULL;
		novo->fim=NULL;
			return novo;
}


void inserefim(fila *f, int num)
{
	lista* p = (lista*) malloc(sizeof(lista));
	p->valor = num;
	p->proximo = NULL;
		if (f->fim != NULL) // verifica se lista não estava vazia 
			{
			f->fim->proximo = p;
			}
				f->fim=p;
					if (f->inicio==NULL) 
					{
					f->inicio = f->fim;
					}
}


int retirafila (fila *f)
{
 int v;
			 if (filavazia(f)==1)
			 {
				printf("Fila vazia.\n");
				exit (1); 
			 }
				v = f->inicio->valor;
				f->inicio = f->inicio->proximo; 
					if (f->inicio == NULL) 
					{
					f->fim = NULL;
					}
 return v;
}

void buscabfs(Grafo *g)
{
	int x, i=0, j, val, y=0;
		printf("De qual nodo deseja iniciar a busca?\n");
		scanf("%d", &val);
		setbuf(stdin, NULL);
				fila *nova=criafila();
				inserefim(nova, val);
				Nodo *aux=busca(g, val);
				int *visitado=(int *) malloc(sizeof(int));		
					while((filavazia(nova))!=1)
					{					
							val=retirafila(nova);	
						printf("Retirando:%d\n", val);
								aux=busca(g, val);	
									y=0;		
							for(j=0;j<i;j++)
							{
								if(visitado[j]==val)
								{
									y++;
								}
							}
								if(y==0)
								{
								visitado[i]=val; //marquei como visitado
									i++;
									Aresta*temp=aux->adjacente;
										while(temp!=NULL)
										{				
										inserefim(nova,temp->chave_adjacente);
											temp=temp->proximo;
										}	
								}
									//Aresta*temp=aux->adjacente;
											//while(temp!=NULL)
											//{				
											//inserefim(nova,temp->chave_adjacente);
											//temp=temp->proximo;
											//}	
										//val=retirafila(nova);	
						//printf("Retirando:%d\n", val);
										//aux=busca(g, val);	
										//y=0;
					}
					printf("----\n");
								printf("\nA ordem de busca BFS segue abaixo\n");
							for(j=0;j<i;j++)
							{
								printf("%d\t", visitado[j]);
							}
}
