#include<stdio.h>
#include<stdlib.h>
#define TAM 7
int visited[TAM];
int grafo[TAM][TAM];

typedef struct lista
{
	int chave;
	int peso;
	struct lista *prox;
}Lista; 

typedef struct grafo
{
	Lista *adj;
}Grafo;

void insereAresta(int chave, int n, int peso, Grafo *g)
{
	Lista *novo=(Lista*)malloc(sizeof(Lista));

	if(g[n].adj==NULL)
	{
		novo->chave = chave;
		novo->peso = peso;
		novo->prox = NULL;
	}

	else
	{
		novo->chave = chave;
		novo->peso = peso;
		novo->prox = g[n].adj;
	}

	g[n].adj=novo;
}

void percorre(int v, Grafo *g) 
{
	Lista *aux=g[v].adj;

	visited[v] = 1;

	while(aux!=NULL)
	{
		if (!visited[aux->chave]) percorre(aux->chave, g);
		aux=aux->prox;
	}
}

int conexo(void)
{
	int i;

	for(i=0;i<TAM;i++)
	{
		if(visited[i]==0)
			return 1;
	}
	return 0;
}

int main (void)
{
	Grafo g[TAM];
	int con, i;

	for(i=0;i<TAM;i++)
		g[i].adj=NULL;

	insereAresta(0, 1, 28, g);
	insereAresta(1, 0, 28, g);

	insereAresta(0, 5, 10, g);
	insereAresta(5, 0, 10, g);

	insereAresta(1, 2, 16, g);
	insereAresta(2, 1, 16, g);

	insereAresta(1, 6, 14, g);
	insereAresta(6, 1, 14, g);

	insereAresta(6, 3, 18, g);
	insereAresta(3, 6, 18, g);

	insereAresta(6, 4, 24, g);
	insereAresta(4, 6, 24, g);

	insereAresta(4, 5, 25, g);
	insereAresta(5, 4, 25, g);

	insereAresta(2, 3, 15, g);
	insereAresta(3, 2, 15, g);

	percorre(0, g);
	con=conexo();

	if(con==1)
		printf("Nao eh conexo\n");
	else
		printf("Eh conexo\n");

	return 0;
}