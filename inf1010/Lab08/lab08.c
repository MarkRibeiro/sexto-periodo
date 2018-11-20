#include <stdio.h>
#include<time.h>
#define SIZE 35
char tabela[SIZE][40];
void criaVetor(void)
{
	int i;

	for(i=0;i<SIZE;i++)
		*tabela[i] = -1;
}
int hash(int tamanho)
{
	int coli=0;
	char s[40];
	FILE *f = fopen("nomes.txt", "r");

	while(!feof(f))
	{
		fscanf(f, "%s", s);
		printf("%s\n", s);
	}
	fclose(f);
	return coli;
}
int main (void)
{
	int i, coli=0;
	clock_t t[2];
	double tempo;

	criaVetor();

	t[0]=clock();
	coli=hash(SIZE);
	t[1]=clock();

	tempo=(t[1] - t[0]) * 1000.0/CLOCKS_PER_SEC;
	return 0;

}