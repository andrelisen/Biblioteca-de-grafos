#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"
int *makeset(int qnt) //criando o "conjunto"
{
	int  i;
	int *conjA=(int*) malloc(sizeof(int));
		for(i=0;i<qnt;i++)
		{
		conjA[i]=i;	
		}
return conjA;
}	

void imprimeConj(int num, int *vet)
{
	if(num<1)
	{
		printf("Vazio");
	}
	int i;
		for(i=0;i<num;i++)
		{
			printf("[%d]\t", vet[i]);
		}
	printf("\n");
}


void uniao(int *vet, int i, int j)
{
	vet[i]=findset(vet, j);
}

int findset(int *vet, int j)
{
	if(vet[j]==j)
	{
		return j;
	}
		else{
				vet[j]=findset(vet,vet[j]);
				return vet[j];
		}
}

//HEAP

void criaHeap(Aresta *a, int u, int v, int peso) 
{
				Aresta *novo=(Aresta*) malloc(sizeof(Aresta));
				novo->chave_partida=u;
				novo->chave_adjacente=v;
				novo->peso=peso;
				novo->proximo=NULL;
					if(a->proximo==NULL)
					{
						a->proximo=novo;
					}
						else{
							Aresta *aux=a->proximo;
								while(aux->proximo!=NULL)
								{
									aux=aux->proximo;
								}
									aux->proximo=novo;
							}
}	

int *percorre(int *vet, int tam)
{
	int j, k, temp=0;
		for(j=0;j<tam;j++)
		{
			for(k=j+1;k<tam;k++)
			{
				if(vet[j]>vet[k])
				{
					temp=vet[j];
						vet[j]=vet[k];
							vet[k]=temp;
				}
			}
		}
return vet;
}
int esquerda(int pos)
{
	int aux;
	aux=2*pos+1;
	return aux;
}

int direita(int pos)
{
	int aux;
	aux=2*pos+2;
	return aux;
}

void MinHeapify(int *vet, int pos, int num)
{
	int cont=0;
	int e=esquerda(pos);//posição
	int d=direita(pos);//posição
	int menor=pos, aux;//posição
		if(e<num && vet[e]<vet[pos])
		{
			menor=e;
		}
			if(d<num && vet[d]<vet[pos])
			{
				menor=d;
			}
				if(menor != pos && menor<num)
				{
				aux=vet[pos];
					vet[pos]=vet[menor];
						vet[menor]=aux;
						MinHeapify(vet, menor, num);
				}
				else{
					cont=pos;//porque nem todos os elementos estavam andando! ex.: chegava no fim do ramo da esq e não voltava
						cont=cont+1;
							if(cont<num)
							{
							MinHeapify(vet, cont, num);
							}
				}
}

int *deleta(int *vet, int num, int *vaux)
{
	//imprimeConj(num, vet);
	int val, i;
		if(num==0)
		{
			printf("A HEAP esta vazia!");
			//return vet;
		}
			else{
				int *vaux=(int *) malloc(sizeof(int));
					int j=0;
					num=num-1;
						for(i=1;i<=num;i++)
						{
							val=vet[0];
								vaux[j]=vet[i];
							imprimeConj(j, vaux);	
							j++;
						}
						printf("-->\n");
						imprimeConj(j, vaux);	
						free(vet);
						printf("valor de num%d\n", num);
							//for(i=0;i<num;i++)
							//{
								//MinHeapify(vaux, i, num);
							//}
							
							printf("Valor retirado %d\n", val);
							printf("<--\n");
						imprimeConj(j, vaux);	
			//return vaux;
			}
}

void raiz(int *vet, int num)
{
	int r;
	if(num>0)
	{
		r=vet[0];
		printf("Raiz da HEAP = %d\n", r);
	}
	else{
		printf("Vazio");
	}
}


void ordena(Aresta *vetor)
{
		Aresta *auxiliar=vetor->proximo;
		int peso1=0, peso2=0, troca=0;
		Aresta *temp=(Aresta*) malloc(sizeof(Aresta));
			while(auxiliar != NULL)
			{
					if(auxiliar->proximo!=NULL)
					{
						Aresta *no=auxiliar;
						while(no!=NULL)
						{
						//printf("valor de 1=%d\n", peso1);
							peso1=no->peso;
							peso2=no->proximo->peso;
					//		printf("valor de 2=%d\n", peso2);
								if(peso2<peso1)
								{
								temp->chave_partida=no->proximo->chave_partida;
									temp->chave_adjacente=no->proximo->chave_adjacente;
										temp->peso=no->proximo->peso;
								no->proximo->chave_partida=no->chave_partida;
									no->proximo->chave_adjacente=no->chave_adjacente;
										no->proximo->peso=no->peso;
								no->chave_partida=temp->chave_partida;
									no->chave_adjacente=temp->chave_adjacente;
										no->peso=temp->peso;
								troca=peso2;
								peso2=peso1;
								peso1=troca;
								}
						no=no->proximo;
						}
					}	
			auxiliar=auxiliar->proximo;
			}
}
