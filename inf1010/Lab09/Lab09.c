#include<stdio.h>
#include<stdbool.h>
#define MAX_VERTICES 7
int grafo[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

typedef struct no
{
	int chave[2];
	struct no *menor;
	struct no *meio;
	struct no *maior;
}No;
int buscaNaArvB(int n, No *arv)
{
	if(n==arv->chave[0] || n==arv->chave[1])
		return 1;
	if(arv->menor==NULL)
		return 0;

	if(n<arv->chave[0])
		return buscaNaArvB(n, arv->menor);

	else if(n>arv->chave[1])
		return buscaNaArvB(n, arv->maior);

	else
		return buscaNaArvB(n, arv->meio);
}

void exibechave(int lim_in, int lim_sup, No *arv)
{
	if(arv->menor!=NULL)
		exibechave(lim_in, lim_sup, arv->menor);

	if(arv->chave[0]>=lim_in && arv->chave[0]<=lim_sup)
		printf("%d ",arv->chave[0]);

	if(arv->meio!=NULL)
		exibechave(lim_in, lim_sup, arv->meio);

	if(arv->chave[1]>=lim_in && arv->chave[1]<=lim_sup)
		printf("%d ", arv->chave[1]);

	if(arv->maior!=NULL)
		exibechave(lim_in, lim_sup, arv->maior);
}

void dfs(int v) 
{
	int w;

	printf("%3d", v);
	visited[v] = 1;
	for (w = 0; w < MAX_VERTICES; w++)
	if (grafo[v][w] && !visited[w]) dfs(w);
}

void imprimebsf(int i)
{
	int cont=0, aux=0, x=0;
	int j, lista[5];
	while(cont<MAX_VERTICES)
	{
		printf("%d\n", i);
		visited[i]=true;
		for(j=0;j<MAX_VERTICES;j++)
		{
			if(grafo[i][j] && !visited[j])
			{
				lista[aux]=j;
				aux=(aux+1)%5;
			}
		}
		i = lista[x];
		x = (x +1)%5;
		cont++;
	}
}

int main (void)
{
	No *arv; 
	int n, ret, lim_in, lim_sup;
	grafo[0][5]=true;
	grafo[0][1]=true;
	grafo[5][0]=true;
	grafo[5][4]=true;
	grafo[4][5]=true;
	grafo[4][6]=true;
	grafo[6][4]=true;
	grafo[6][3]=true;
	grafo[6][1]=true;
	grafo[3][6]=true;
	grafo[1][6]=true;
	grafo[1][0]=true;
	grafo[1][2]=true;
	grafo[2][1]=true;

	//ret=buscaNaArvB(n, arv);

	imprimebsf(0);
/*
	switch (ret)
	{
		case 0:
		printf("%d nao esta na arvore\n", n);

		case 1:
		printf("%d esta na arvore\n", n);
	}

	exibechave(lim_in, lim_sup, arv);
	*/
	return 0;
}