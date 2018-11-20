#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	struct tree *e;
	struct tree *d;
	int chave; 
}Tree;
Tree* criaArv(int n)
{
	Tree* nova = (Tree*)malloc(sizeof(Tree));
	if(nova==NULL)
	{
		printf("Sem memoria\n");
		exit(1);
	}

	nova->chave=n;
	nova->e=NULL;
	nova->d=NULL;

	return nova;
}
Tree* insereArv(Tree *a, int n)
{
	if(a==NULL)
	{
		a=criaArv(n);
		return a;
	}
	if(a->chave>n)
		a->e=insereArv(a->e, n);

	else
		a->d=insereArv(a->d, n);

	return a;
}
int main()
{
	Tree *a;

	printf("foi\n");
	return 0;
}
