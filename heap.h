//para o CONJUNTOS/DISJUNTOS
int *makeset(int qnt);
int *uniao(int *vet, int i, int j);//union
int findset(int *vet, int j);//representante do elem atual ser = ao repres do atual representante
void imprimeConj(int num, int *vet);
//HEAP
Aresta *criaHeap(Aresta *vetor, int u, int v, int peso, int quantidade, int tam);
Aresta *deleta(Aresta *vetor, int num);
Aresta *raiz(Aresta *vet, int num);
void percorre(Aresta *vet, int tam);
