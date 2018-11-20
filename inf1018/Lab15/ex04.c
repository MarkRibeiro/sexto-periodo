#include<stdio.h>
#include<math.h>
double foo3 (double *a, int n);
int main ()
{
	double v[3]={5, 9, 3};
	printf("%lf\n", foo3(v, 3));
}