#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree
{
	int key;
	struct tree *l;
	struct tree *r;
}Tree;

int AVL(Tree* Arv);
int verifyAVL(Tree* Arv);
Tree* createNode(int key);
Tree* insert(int key, Tree* arv);

int main(void)
{
	Tree* arv1 = NULL, *arv2 = NULL;
	int vetor1[15] = {11,7,15,5,9,13,17,4,6,8,10,12,14,16,18}, i = 0;
	int vetor2[15] = {11,7,15,5,13,17,4,6,8,9,10,12,14,16,18};

	for(i = 0; i < 15; i++)
		arv1 = insert(vetor1[i], arv1);
	for(i = 0; i < 15; i++)
		arv2 = insert(vetor2[i], arv2);

	if(verifyAVL(arv1) == 1)
		printf("Arv1 eh AVL\n");
	else
		printf("Arv1 nao e AVL\n");
	if(verifyAVL(arv2) == 1)
		printf("Arv2 eh AVL\n");
	else
		printf("Arv2 nao eh AVL\n");
	return 0;
}

int AVL(Tree* Arv)
{
	int l, r;
	if(Arv == NULL)
		return -1;

	l = AVL(Arv->l);
	r = AVL(Arv->r); 

	return abs(l-r);;
}

int verifyAVL(Tree* Arv)
{
	return AVL(Arv) < 2;
}

Tree* createNode(int key)
{
	Tree* new = (Tree*) malloc(sizeof(Tree));
	new->key = key;
	new->r = NULL;
	new->l = NULL;
	return new;
}

Tree* insert(int key, Tree* arv)
{

	if(arv == NULL)
		return createNode(key);

	else if(key < arv->key)
		arv->l = insert(key,arv->l);

	else if (key > arv->key)
		arv->r = insert(key,arv->r);
	
	return arv;
}
