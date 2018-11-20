#include<stdio.h>
void foo (int a[], int n); 	
int main (void)
{
	int a[6]={1, 2, 3, 0, 5, 0};
	int i;
	
	foo(a, 6);
	
	for(i=0;i<6;i++)
	{
		printf("v[%d]=%d\n", i, a[i]);
	}
	
	return 0;
}
