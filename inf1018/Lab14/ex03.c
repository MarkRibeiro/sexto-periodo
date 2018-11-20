#include<stdio.h>
typedef int (*funcp) (int x);
unsigned char codigo[]={0x83, 0xc7, 0x01, 0x89, 0xf8, 0xc3};
int main (void)
{
	funcp f;
	int i;

	f = (funcp)codigo;
	i = (*f)(10);
	printf("%d\n", i);
}