#include<stdio.h>
float foo(double a, float b);
int main ()
{
	double a=2.0;
	float b=5.0;
	printf("%.2f\n", foo(a, b));

	return 0;
}