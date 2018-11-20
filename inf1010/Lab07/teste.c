#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void)
{
	FILE *f = fopen("placas.txt", "r");
	char p[7];
	int numero;

	fscanf(f, "%s\n", p);

	numero=p[0] + p[1] + p[2] + (p[3] - '0')*1000 + (p[4] - '0')*100 + (p[5] - '0')*10 + (p[6] - '0');
	printf("%s = %d\n", p, numero);
	fclose(f);
	return 0;

}