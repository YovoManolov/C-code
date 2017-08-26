#include <stdio.h>
 int main (void)
{
	int a, b,c;
	printf ("insert two numbers");
	
	printf ("collect-1,take - 2 ");
	
	scanf("%i",& c);
	
	printf ("insert number a");
	scanf("%i", & a);
	printf ("insert number b");
	scanf("%i", & b);
	
    if(c == 1) printf (a+b);
	if(c == 2) printf (a-b);
	
	return 0;

}
