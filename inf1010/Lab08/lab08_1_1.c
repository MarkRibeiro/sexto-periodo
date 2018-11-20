#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 35

char vetor[40][SIZE];
int coli;

int hash(char* palavra);

int main (void)
{

	char *palavra;
	FILE *f = fopen("nomes.txt","r");
	int i, posi;

	for(i=0;i<SIZE;i++)
	{
		palavra = (char*) malloc(40*sizeof(char));
		fread(palavra,40,1,f);
		posi = hash(palavra);
	}

	printf("Colisoes:%d\n",coli);
	fclose(f);

	return 0;
}

int hash(char* palavra)
{

	int posi,i;
	char aux = 0;

	for(i=0;i<SIZE;i++)
	{
		aux = aux + palavra[i]*23;
	}

	posi = (int)aux % SIZE;

	for(i=0; i<SIZE;i++)
	{
		if(vetor[40][posi] == NULL)
		{
			strcpy(&vetor[40][posi],palavra);
			return posi;
		}

		coli++;
		if (strcmp(&vetor[40][posi],palavra)==0)
			return posi;
		posi++;

		if (posi>SIZE)
			posi = posi - SIZE;
	}

	return -1;
}