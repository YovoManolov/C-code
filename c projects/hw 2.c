#include<stdio.h>
int main ()
double a, b ;
void f1();
{
    printf ("%3d",f1() );
	return 0; 
	
}

void f1 (void)
{
    printf("Enter two double numbers: ");
	scanf("%d",   a);
	scanf("%d", b);
	printf("%d", a*b);
}
