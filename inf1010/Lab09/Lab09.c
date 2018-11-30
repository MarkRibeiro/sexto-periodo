#include<stdio.h>
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

int main (void)
{
	No *arv; 
	int n, ret, lim_in, lim_sup;


	ret=buscaNaArvB(n, arv);

	switch (ret)
	{
		case 0:
		printf("%d nao esta na arvore\n", n);

		case 1:
		printf("%d esta na arvore\n", n);
	}

	exibechave(lim_in, lim_sup, arv);

	return 0;
}