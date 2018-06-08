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
Aresta *alocaHeap(Grafo *g)
{
		Nodo*aux=g->listanodos;
		int tam=g->numArestas, i=0;
		Aresta *nova=(Aresta*) malloc(tam*sizeof(Aresta));
			while(aux!=NULL)
			{
				if(aux->adjacente!=NULL)
				{
				//nova[i].chave_partida=aux->adjacente->chave_partida;
					//nova[i].chave_adjacente=aux->adjacente->chave_adjacente;
						//nova[i].peso=aux->adjacente->peso;
						nova=criaHeap(nova, aux->adjacente->chave_partida, aux->adjacente->chave_adjacente, aux->adjacente->peso, i);
				i++;
					if(aux->adjacente->proximo!=NULL)
					{
						Aresta*aux2=aux->adjacente->proximo;
							while(aux2!=NULL)
							{
								//nova[i].chave_partida=aux2->chave_partida;
									//nova[i].chave_adjacente=aux2->chave_adjacente;
										//nova[i].peso=aux2->peso;
								nova=criaHeap(nova, aux2->chave_partida, aux2->chave_adjacente, aux2->peso, i);
									i++;
								aux2=aux2->proximo;
							}
					}	
				}
				aux=aux->proximo;
			}	
				//printf("--ANTES--\n");
			//for(i=0;i<tam;i++)
			//{
				//printf("VEZ=%d\t[%d]->[%d]--(%d)\n", i, nova[i].chave_partida, nova[i]. chave_adjacente, nova[i].peso);
			//}
	//printf("\n--\nValor =%d\n---\n", tam);
		percorre(nova, tam);
				//printf("--DEPOIS--\n");
			//for(i=0;i<tam;i++)
			//{
				//printf("VEZ=%d\t[%d]->[%d]--(%d)\n", i, nova[i].chave_partida, nova[i]. chave_adjacente, nova[i].peso);
			//}
return nova;
}

Aresta *criaHeap(Aresta *vetor, int u, int v, int peso, int posicao)
{
	vetor[posicao].chave_partida=u;
		vetor[posicao].chave_adjacente=v;
			vetor[posicao].peso=peso;
				return vetor;
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
//int esquerda(int pos)
//{
	//int aux;
	//aux=2*pos+1;
	//return aux;
//}

//int direita(int pos)
//{
	//int aux;
	//aux=2*pos+2;
	//return aux;
//}

//void MinHeapify(Aresta *vet, int pos, int num)
//{
	//int cont=0;
	//int e=esquerda(pos);//posição
	//int d=direita(pos);//posição
	//int menor=pos, aux;//posição
		//if(e<num && vet[e]<vet[pos])
		//{
			//menor=e;
		//}
			//if(d<num && vet[d]<vet[pos])
			//{
				//menor=d;
			//}
				//if(menor != pos && menor<num)
				//{
				//aux=vet[pos];
					//vet[pos]=vet[menor];
						//vet[menor]=aux;
						//MinHeapify(vet, menor, num);
				//}
				//else{
					//cont=pos;//porque nem todos os elementos estavam andando! ex.: chegava no fim do ramo da esq e não voltava
						//cont=cont+1;
							//if(cont<num)
							//{
							//MinHeapify(vet, cont, num);
							//}
				//}
//}

Aresta *deleta(Aresta *vet, int num)
{
		int i, j=0,u=0, v=0, peso=0;
		if(num==0)
		{
			printf("A HEAP esta vazia!");
			return vet;
		}
			else{
				num=num-1;
						for(i=0;i<num;i++)
							{
							u=vet[0].chave_partida;
								v=vet[0].chave_adjacente;
									peso=vet[0].peso;
							vet[i].chave_partida=vet[i+1].chave_partida;
								vet[i].chave_adjacente=vet[i+1].chave_adjacente;
									vet[i].peso=vet[i+1].peso;
							}
			return vet;
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
		//r=vet[0].chave_partida;
	//	printf("Raiz da HEAP = %d\n", r);
	return retorno;
	}
}

Aresta *heapPrior(Grafo *g, int valor, Aresta *adj)
{
	Nodo *no=g->listanodos;
		int tam=g->numArestas, i=0;
			tam=tam-1;
			//	Aresta *adj=(Aresta*) malloc(tam * sizeof(Aresta)); //maximo de vertices ligados nesse nodo é de TAM-1
		while(no!=NULL)
		{
			if(no->adjacente!=NULL)
			{
				if(no->adjacente->chave_partida == valor)
				{
					//adjacente[i].chave_partida=no->adjacente->chave_partida;
						//adjacente[i].chave_adjacente=no->adjacente->chave_partida;
							//adjacente[i].peso=no->adjacente->peso;
					adj=criaHeap(adj, no->adjacente->chave_partida, no->adjacente->chave_adjacente, no->adjacente->peso, i);
					i++;	
						if(no->adjacente->proximo!=NULL)
						{
							Aresta *no2=no->adjacente->proximo;
								while(no2!=NULL)
								{
									//adjacente[i].chave_partida=no2->chave_partida;
										//adjacente[i].chave_adjacente=no2->chave_partida;
											//adjacente[i].peso=no2->peso;								
								adj=criaHeap(adj, no2->chave_partida, no2->chave_adjacente, no2->peso, i);
								i++;
								no2=no2->proximo;
								}
						}
				}
			}
		no=no->proximo;
		}
			percorre(adj, i);
return adj;
}

