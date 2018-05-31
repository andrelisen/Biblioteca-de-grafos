//para utilizar na DFS
struct PILHA{
	int valor;
	struct PILHA *proximo;
};typedef struct PILHA pilha;

pilha *criapilha(void);//inicializar
int vazia(pilha *pi);
void push(pilha *pi, int valor);//colocar 
int pop(pilha *pi);//retirar
void exibe(pilha *pi);
void buscadfs(Grafo *g);

//para utilizar na BFS
struct LISTA{
	int valor;
	struct LISTA *proximo;
}; typedef struct LISTA lista;

struct FILA {
	struct LISTA *inicio;
	struct LISTA *fim;
}; typedef struct FILA fila;

int filavazia(fila *f);
fila *criafila(void);
int retirafila(fila *f);
void inserefim(fila *f, int num);
void buscabfs(Grafo *g);
Nodo *buscanodo(Nodo *g, int valor);
