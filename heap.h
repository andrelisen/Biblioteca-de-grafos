//para o CONJUNTOS/DISJUNTOS
int *makeset(int qnt);
void uniao(int *vet, int i, int j);//union
int findset(int *vet, int j);//representante do elem atual ser = ao repres do atual representante
void imprimeConj(int num, int *vet);
//HEAP
int *criaHeap(int *vet, int qnt, int valor);
void organiza(int *vet, int qnt);
void MinHeapify(int *vet, int pos, int num);
int esquerda(int pos);
int direita(int pos);
int *deleta(int *vet, int num, int*vaux);
void raiz(int *vet, int num);
int *percorre(int *vet, int tam);
