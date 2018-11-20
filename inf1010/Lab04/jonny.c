#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#define COUNT 10
#define SIZE 10
typedef struct node 
{ 
    int data; 
    struct node* left, *right; 
}Node; 
   
Node* newNode(int data) 
{ 
    Node* node;
	node=(Node*)malloc(sizeof(Node));
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL) return newNode(data);
 
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);   
 
    return node;
} 

void print2DUtil(Node *root, int space) 
{ 
    if (root == NULL) 
        return; 
  
    space += COUNT; 
  
    print2DUtil(root->right, space); 
  
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    print2DUtil(root->left, space); 
} 

int iguais(Node* a,Node* b)
{
	if(a==NULL && b==NULL)
		return 1;
	
	if(a==NULL || b==NULL)
		return 0;

	return ((a->data==b->data) && iguais(a->left,b->left) && iguais(a->right,b->right));
}
static int compara (const void* x, const void* y)
{
	int r = *(int*) x;
	int q = *(int*) y;

	return r-q;
}
Node* AbbMenor(int*v, int ini, int fim, Node *arv)
{
	int meio = (ini+fim)/2;

	if(ini >= fim)
	{
		arv = insert(arv, v[meio]);
		return arv;
	}
	
	arv = insert(arv, v[meio]);
	arv = AbbMenor(v, ini, meio-1, arv);
	arv = AbbMenor(v, meio+1, fim, arv);

	return arv;
}
void iniciar_aleatorio(void)
{
	srand((unsigned int)time(NULL));
	rand();
	rand();
	rand();
}
int main() 
{ 
    struct node *arv1 = NULL, *arv2 = NULL;
	int va1[SIZE]={2, 7, 41, 14, 16, 1, 0}; 
	int va2[SIZE]={41, 1, 16, 2, 7, 14, 0};
	int i=0, j=0;

	iniciar_aleatorio();	

	while(i<SIZE)
	{
		va1[i]=rand() %1000;
		i++;
	}

	while(j<SIZE)
	{
		va2[j]=rand() %1000;
		j++;
	}

	qsort(va1, SIZE, sizeof(int), compara);
	qsort(va2, SIZE, sizeof(int), compara);

	
		
	arv1 = AbbMenor(va1, 0, SIZE-1, arv1);
	printf("**********Arvore 1**********\n");
	print2DUtil(arv1, 0);
	printf("\n");
	
	arv2 = AbbMenor(va2, 0, SIZE-1, arv2);
	printf("**********Arvore 2**********\n");
	print2DUtil(arv2, 0);
	printf("\n");

	if(iguais(arv1,arv2)==0)
		printf("arv1 e arv2 sao diferentes");
	else
		printf("arv1 e arv2 sao iguais");
	
    return 0; 
} 

