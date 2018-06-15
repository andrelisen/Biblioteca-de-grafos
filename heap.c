#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"
int *makeset(int qnt) //criando o "conjunto"
{
	int  i;
	int *conjA=(int*) malloc(qnt * sizeof(int));
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
	printf("\nConjuntos\n");
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

Aresta *criaHeap(Aresta *vetor, int u, int v, int peso, int quantidade, int tam)
{
	Aresta *vet=(Aresta*) malloc(tam * sizeof(Aresta));
	int i=0, quant=quantidade; 
					quant=quant-1;               
		if(quantidade==1) 
		{
			vet[0].chave_partida=u;
				vet[0].chave_adjacente=v;
					vet[0].peso=peso;
						return vet;
		}
		else{
			  		while(i<quant)
					{
						vet[i].chave_partida=vetor[i].chave_partida;
							vet[i].chave_adjacente=vetor[i].chave_adjacente;
								vet[i].peso=vetor[i].peso;	
					i++;
					}
					vet[i].chave_partida=u;
						vet[i].chave_adjacente=v;
							vet[i].peso=peso;
			return vet;
		}
}

void percorre(Aresta *vet, int tam)
{
	int j, k, u=0, v=0, peso=0;
		for(j=0;j<tam;j++)
		{
			for(k=j+1;k<tam;k++)
			{
				if(vet[j].peso>vet[k].peso)
				{
					u=vet[j].chave_partida;
						v=vet[j].chave_adjacente;
							peso=vet[j].peso;
					vet[j].chave_partida=vet[k].chave_partida;
						vet[j].chave_adjacente=vet[k].chave_adjacente;
							vet[j].peso=vet[k].peso;
					vet[k].chave_partida=u;
						vet[k].chave_adjacente=v;
							vet[k].peso=peso;
				}
			}
		}
}

Aresta *deleta(Aresta *vetor, int num)
{
	int i, j=0,cont=num;	
		num=num-1;
			if(num==0)
			{
					return vetor;
			}
			else{
							for(i=1;i<=cont;i++)
							{
							vetor[j].chave_partida=vetor[i].chave_partida;
								vetor[j].chave_adjacente=vetor[i].chave_adjacente;
									vetor[j].peso=vetor[i].peso;
							j++;
							}
			percorre(vetor, num);
			return vetor;
			}
}

Aresta *raiz(Aresta *vet, int num)
{
	Aresta *retorno=(Aresta*) malloc(1 * sizeof(Aresta));
	if(num>0)
	{
		retorno[0].chave_partida=vet[0].chave_partida;
			retorno[0].chave_adjacente=vet[0].chave_adjacente;
				retorno[0].peso=vet[0].peso;
	return retorno;
	}
}
