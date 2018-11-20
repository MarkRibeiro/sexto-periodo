#include<stdio.h>
int main ()
{
	char i=9;
	char x;
	int sv=2;

	x= i >>sv;

	printf("%d >> %d: %d\n", i, sv,x);
	sv=2;
	x= i << sv;

	printf("%d << %d: %d\n", i, sv,x);
	return 0;
}