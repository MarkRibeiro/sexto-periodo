#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	struct tree *e;
	struct tree *d;
	int chave;
	int fb;
}Tree;

int maior(int a, int b);
int getBalance(Tree *a);
int altura(Tree *a);
Tree* giraEsq(Tree *x);
Tree* giraDir(Tree *y);
Tree* insereArv(Tree *a, int chave);

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
	nova->fb=0;

	return nova;
}
/*
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
*/
void print2DUtil(Tree *t, int space) 
{ 
    if (t == NULL) 
        return; 
  
    space += 10; 
  
    print2DUtil(t->d, space); 
  
    printf("\n"); 
    for (int i = 10; i < space; i++) 
        printf(" "); 
    printf("%d\n", t->chave); 
  
    print2DUtil(t->e, space); 
} 

int main ()
{
	Tree *a=NULL;

	a=insereArv(a, 8);
	a=insereArv(a, 5);
	a=insereArv(a, 10);
	a=insereArv(a, 11);
	a=insereArv(a, 12);
	a=insereArv(a, 13);
	a=insereArv(a, 4);
	a=insereArv(a, 3);
	print2DUtil(a, 0);
	return 0;
}

int maior(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int getBalance(Tree *a) 
{ 
    if (a == NULL) 
        return 0; 

    return altura(a->e) - altura(a->d); 
} 

int altura(Tree *a) 
{ 
    if (a == NULL) 
        return 0; 
    
    return a->fb; 
}

Tree* giraEsq(Tree *x) 
{ 
    Tree *y = x->d; 
    Tree *T2 = y->e; 
  
    y->e = x; 
    x->d = T2; 
  
    x->fb = maior(altura(x->e), altura(x->d))+1; 
    y->fb = maior(altura(y->e), altura(y->d))+1; 
   
    return y; 
} 

Tree* giraDir(Tree *y) 
{ 
    Tree *x = y->e; 
    Tree *T2 = x->d; 
  
    x->d = y; 
    y->e = T2; 
  
    y->fb = maior(altura(y->e), altura(y->d))+1; 
    x->fb = maior(altura(x->e), altura(x->d))+1; 
  
    return x; 
}

Tree* insereArv(Tree* a, int chave) 
{ 
    if (a == NULL) 
        return(criaArv(chave)); 
  
    if (chave < a->chave) 
        a->e  = insereArv(a->e, chave);

    else if (chave > a->chave) 
        a->d = insereArv(a->d, chave);

    else 
        return a; 
  
    a->fb = 1 + maior(altura(a->e), altura(a->d)); 
  
    int balance = getBalance(a); 
  
    if (balance > 1 && chave < a->e->chave) 
        return giraDir(a); 
  
    if (balance < -1 && chave > a->d->chave) 
        return giraEsq(a); 
  
    if (balance > 1 && chave > a->e->chave) 
    { 
        a->e =  giraEsq(a->e); 
        return giraDir(a); 
    } 
  
    if (balance < -1 && chave < a->d->chave) 
    { 
        a->d = giraDir(a->d); 
        return giraEsq(a); 
    } 
  
    return a; 
}