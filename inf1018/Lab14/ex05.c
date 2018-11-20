#include<stdio.h>
typedef int (*funcp) (int x);
unsigned char codigo[]={0xe8, 0x00, 0x00, 0x00, 0x00, 0xc3};

int add (int x) 
{
  return x+1;
}

int main (void)
{
	funcp f;
	int i, l;
	unsigned char *p;

	l = (long) &add  - (long) &codigo[5];

	p = (unsigned char *) &l;

	for(i=1;i<5;i++)
	{
		codigo[i]=*p;
		p++;
	}


	f = (funcp)codigo;
	i = (*f)(10);
	printf("%d\n", i);
}