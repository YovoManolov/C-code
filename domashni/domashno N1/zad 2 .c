#include<stdio.h>
double a,b ;
double proizwedenie();
int main ()
{	
	printf("enter  number1(double):");
	scanf("%lf",& a);
	printf("enter  number2(double):");
	scanf("%lf",& b);
	proizwedenie();
	
	return 0;
}
double proizwedenie (a,b){
	printf(" proizvedenieto ot a i b e = %3lf\n", a*b );
}
