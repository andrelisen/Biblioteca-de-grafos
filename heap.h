//para o CONJUNTOS/DISJUNTOS
int *makeset(int qnt);
void uniao(int *vet, int i, int j);//union
int findset(int *vet, int j);//representante do elem atual ser = ao repres do atual representante
void imprimeConj(int num, int *vet);
//HEAP
Aresta *criaHeap(Aresta *vetor, int u, int v, int peso, int posicao);
Aresta *alocaHeap(Grafo *g);
Aresta *heapPrior(Grafo *g, int valor, Aresta *adj);
void MinHeapify(Aresta *vet, int pos, int num);
int esquerda(int pos);
int direita(int pos);
Aresta *deleta(Aresta *vet, int num);
Aresta *raiz(Aresta *vet, int num);
void percorre(Aresta *vet, int tam);
