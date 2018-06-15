#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "funcao.h"
#include "busca.h"
#include "heap.h"
#include "guloso.h"

int quantidade(void) //lê a quantidade de vertices e retorna ela 
{
FILE *arquivo;
int val;
	if ((arquivo = fopen("entrada.txt", "r")) == NULL)
	{
	printf("Impossivel realizar a leitura do arquivo. Tente novamente\n");
	}
	//Leitura da quantidade de vertices do meu grafo
		fscanf(arquivo, "%d", &val);
		fclose(arquivo);
		return val;
}

Grafo *cria(int quantidade)
{
int i;	
	Grafo *g=(Grafo *) malloc(sizeof(Grafo)); //cria o grafo todo
	g->tamanho=quantidade; //verificar se aqui não é o tamanho de nodos que estão sendo ligados ou é a quantidade
	g->listanodos=NULL;
	g->numArestas=0;
		for(i=0;i<quantidade;i++) //alocando chave por chave
		{
			Nodo *no=(Nodo *) malloc(sizeof(Nodo)); //cria nodo EX.:v[0],v[1]
			no->chave=i; //atualizo o valor do meu nodo para a minha chave que é a origem
			no->proximo=NULL; //proximo ao meu nodo apontar para NULL
			no->adjacente=NULL; //o destino do meu nodo é inicializado com NULL, logo não aponta para nada
			if(g->listanodos==NULL)//significa que é o meu primeiro nó
			{
				g->listanodos=no; 
			}
				else{  
					Nodo *no2=g->listanodos; //Estava errando aqui pois mexia diretamente no grafo!!
					while(no2->proximo!=NULL) //enquanto o proximo da minha lista de nodos for diferente de VAZIO
					{
						no2=no2->proximo;
					}
							no2->proximo=no;//achou VAZIO? Pois então nesse local vai meu novo nó
					}
		}	
	return g;
}

void criaAresta(Grafo *g)
{
	FILE *arquivo;
	int qnt, origem=0, destino=0, p=0;
		if((arquivo=fopen("entrada.txt", "r"))==NULL)
		{
			printf("ERRO NA LEITURA DO ARQUIVO!\n");
		}
			else{
					fscanf(arquivo, "%d", &qnt);
					printf("Quantidade de nodos:%d\n", qnt);
							while(fscanf(arquivo, "%d%d%d", &origem, &destino,&p)!=EOF)
							{
									Nodo *verifica=busca(g, origem);
										if(verifica == NULL) //quando o valor a ser inserido NÃO existe no meu grafo.
										{
												printf("O valor de origem %d nao esta contido no grafo, usuario\n", origem);
										}
											else{ //valor de origem EXISTE no grafo.
 													Aresta *irma=(Aresta*)malloc(sizeof(Aresta)); //criando aresta do meu destino
													irma->chave_adjacente=destino;
													irma->chave_partida=verifica->chave;
													irma->peso=p; //valor da sua conexão=peso
													irma->proximo=NULL; 
													g->numArestas++; //ætualização do numero de arestas => caminho entre os nodos
													if(verifica->adjacente==NULL)
													{
														verifica->adjacente=irma;
													}
														else{
																Aresta *novo=verifica->adjacente;
																	while(novo->proximo!=NULL)
																	{
																		novo=novo->proximo;
																	}
															novo->proximo=irma;
															}	
												}	
							}
					}		
			printf("Inseriu no grafo com sucesso!\n");
				fclose(arquivo);

}

Nodo *busca(Grafo *g, int valor)
{
		Nodo*aux=g->listanodos;
			while(aux !=NULL)
			{
				if(aux->chave==valor)
				{
				 return aux;	
				}	
				else{
				aux=aux->proximo;
				}
			}
	return NULL;		
}

void imprimeGrafo(Grafo *g)
{
	Nodo *percorre=g->listanodos;
	while(percorre!=NULL)
	{
			printf("%d", percorre->chave);
			if(percorre->adjacente!=NULL)
			{
			printf("-->");
			printf("%d ", percorre->adjacente->chave_adjacente);
			printf("[%d]", percorre->adjacente->peso);
				if(percorre->adjacente->proximo!=NULL) //o que estava acontecendo: estava 'sobrescrevendo' o prox adjacente do meu nodo, via o 1 e dps perdia o resto
				{
					Aresta *aux=percorre->adjacente->proximo;
					while(aux!=NULL)
					{
					printf("-->");
					printf("%d", aux->chave_adjacente);
					printf("[%d]", aux->peso);
					aux=aux->proximo;
					}	
				}
			}
			else{
			printf("-->");
			printf("Sem adjacente");	
			}
			printf("\n");	
			percorre=percorre->proximo;
	}
}
