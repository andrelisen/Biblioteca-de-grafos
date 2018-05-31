struct grafo{ 
	struct nodo *listanodos;
	int tamanho;
};typedef struct grafo Grafo;
struct nodo
{
	int chave;                   //v[0],v[1], v[2]
	struct aresta *adjacente;
	struct nodo *proximo;  //proximo do meu v[0] é v[1]
};typedef struct nodo Nodo;

struct aresta{
	int chave_adjacente; //colado v[0], colado v[1], colado v[2]
	int chave_partida; 
	struct aresta *proximo; 
	int peso; 
};typedef struct aresta Aresta;

int quantidade(void);
Grafo *cria(int quantidade);
void criaAresta(Grafo *g);
void imprimeGrafo(Grafo *g);
Nodo *busca(Grafo *g, int valor);
