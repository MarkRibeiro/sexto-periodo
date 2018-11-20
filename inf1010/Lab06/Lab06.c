#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SiZE 1009

int main (void)
{
	char placas[SIZE];
	FILE *f = fopen("placas.txt", "w");
	int i;

	srand(time(NULL));

	for(i=0;i<1000;i++)
		fprintf(f, "%c%c%c %c%c%c%c \n" , 'A' + rand()%26, 'A' + rand()%26, 'A' + rand()%26, '0' + rand()%10, '0' + rand()%10, '0' + rand()%10, '0' + rand()%10);
	
	fclose(f);
	return 0;

}