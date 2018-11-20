#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 5
//struct da arvore binaria
typedef struct tree
{
	int key;
	struct tree *left;
	struct tree *right;
}Tree;

//inicia a contagem para criar numeros aleatorios
void ini_random(void)
{
	srand((unsigned int)time(NULL));
	rand();
	rand();
	rand();
}

//cria um vetor com numeros aleatorios nao repetidos
void create_vector(int *v)
{
	int i, j;

	for(i=0;i<SIZE;i++)
	{	
		JUMP:
		v[i]=rand() %32;
		for(j=0;j<i;j++)
		{
			if(v[j]==v[i])
				goto JUMP;
		}	
	}
}

int max(int x, int y)
{
	if(x>y)
		return x;

	else
		return y;
}

int comp(const void * a, const void * b)
{
	int x = *(int *)a;
	int z = *(int *)b;

	return x-z;
}

//cria a arvore
Tree* create_tree(int n)
{
	Tree* new_tree = (Tree*) malloc(sizeof(Tree));
	if(new_tree==NULL)
	{
		printf("Sem memoria\n");
		exit(1);
	}
	new_tree->key=0;
	new_tree->key=n;
	new_tree->left=NULL;
	new_tree->right=NULL;

	return new_tree;
}

//insere um ele mento na arvore binaria
Tree* insert_tree (int n)
{
	Tree *new_tree=NULL;

	if(new_tree==NULL)
		return create_tree(n);

	else if(new_tree->key>n)
		new_tree->left=insert_tree (n);

	else
		new_tree->right=insert_tree (n);
	
	return new_tree;
}

//cria a arvore, porem, balanceada 
Tree* balanced_BST(int start, int end, int *v)
{
    int midle = (start+end)/2; 
	Tree *new_tree;

    if(start > end)
	{
        return NULL;
	}

	new_tree = insert_tree(v[midle]);

    new_tree->left = balanced_BST(start, midle-1, v);
    new_tree->right = balanced_BST(midle+1, end, v);
	
	return new_tree;

}
//imprime a arvore em pre-ordem
void print_pre(Tree *t)
{
	if(t!=NULL)
	{
		printf("%d, ", t->key);
		print_pre(t->left);
		print_pre(t->right);
	}
}

//imprime a arvore em ordem simetrica
void print_simetrica(Tree *t)
{
	if(t!=NULL)
	{
		print_simetrica(t->left);
		printf("%d, ", t->key);
		print_simetrica(t->right);
	}
}

//imprime a arvore em pre-ordem
void print_pos(Tree *t)
{
	if(t!=NULL)
	{
		print_pos(t->left);
		print_pos(t->right);
		printf("%d, ", t->key);
	}
}

//imprime a arvore binaria em forma de arvore
void print2DUtil(Tree *t, int space) 
{ 
    if (t == NULL) 
        return; 
  
    space += 10; 
  
    print2DUtil(t->right, space); 
  
    printf("\n"); 
    for (int i = 10; i < space; i++) 
        printf(" "); 
    printf("%d\n", t->key); 
  
    print2DUtil(t->left, space); 
} 

int main (void)
{
	int v[SIZE];
	Tree *t=NULL;

	ini_random();
	create_vector(v);
	qsort(v, SIZE, sizeof(int), comp);
	t=balanced_BST(0, SIZE-1, v);
	printf("Pre ordem [");
	print_pre(t);
	printf("]\n");
	printf("simetrica [");
	print_simetrica(t);
	printf("]\n");
	printf("Pos ordem [");
	print_pos(t);
	printf("]\n");	
	print2DUtil(t, 0);

	return 0;
}



































