//para o CONJUNTOS/DISJUNTOS
int *makeset(int qnt);
void uniao(int *vet, int i, int j);//union
int findset(int *vet, int j);//representante do elem atual ser = ao repres do atual representante
void imprimeConj(int num, int *vet);
//HEAP
Aresta *criaHeap(Grafo *g);
void organiza(int *vet, int qnt);
void MinHeapify(Aresta *vet, int pos, int num);
int esquerda(int pos);
int direita(int pos);
Aresta *deleta(Aresta *vet, int num);
void raiz(int *vet, int num);
void percorre(Aresta *vet, int tam);
