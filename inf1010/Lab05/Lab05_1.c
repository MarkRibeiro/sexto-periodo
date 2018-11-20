#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 5
typedef struct tree
{
	int key;
	int factor_b;
	struct tree *left;
	struct tree *right;
}Tree;

void ini_random(void)
{
	srand((unsigned int)time(NULL));
	rand();
	rand();
	rand();
}

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
void printavector(int *v)
{
	int i;

	for(i=0;i<SIZE;i++)
	{
		printf("v[%d]=%d\n", i, v[i]);
	}
	
}

int max(int x, int y)
{
	if(x>y)
		return x;

	else
		return y;
}

int height(Tree *t) 
{ 
   if(t == NULL) 
       return 0; 
 
   return 1 + max(height(t->left), height(t->right)); 
}  

void calc_factor(Tree *t)
{	
	t->factor_b=abs(height(t->left)-height(t->right));
	
	if(t->left!=NULL)
		calc_factor(t->left);
	if(t->right!=NULL)
		calc_factor(t->right);

}

int comp(const void * a, const void * b)
{
	int x = *(int *)a;
	int z = *(int *)b;

	return x-z;
}

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

Tree* insert_tree (Tree *t, int n)
{
	if(t==NULL)
		return create_tree(n);

	else if(t->key>n)
		t->left=insert_tree (t->left, n);

	else
		t->right=insert_tree (t->right, n);
	
	return t;
}

Tree* balanced_BST(int star, int end, Tree *t, int *v)
{
    int midle = (star+end)/2;

    if(star >= end)
	{
        t = insert_tree(t, v[midle]);
        return t;
    }
	else{
    	t = insert_tree(t, v[midle]);
    	t = balanced_BST(midle+1, end, t, v);
    	t = balanced_BST(star, midle-1, t, v);
	}
return t;
}

void print_BST(Tree *t)
{
	if(t!=NULL)
	{
		print_BST(t->left);
		printf("valor=%d fator de balanco=%d\n", t->key, t->factor_b);
		print_BST(t->right);
	}
}

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
	t=balanced_BST(0, SIZE-1, t, v);
	calc_factor(t);
	print_BST(t);
	print2DUtil(t, 0);
	printavector(v);

	return 0;
}
