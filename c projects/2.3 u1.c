#include <stdio.h>
 int main (void)
{
	int a, b,c;
	printf (" insert two numbers");
	
	printf (" collect-1,take - 2 : ");
	scanf("%d",& c);
	
	if (c == 1) { 
	printf ("insert number a");
	scanf("%d", & a);
	printf ("insert number b");
	scanf("%d", & b);
	printf("%d", a+b);
}
else { 
	
	printf ("insert number a");
	scanf("%d", & a);
	printf ("insert number b");
		scanf("%d", & b);
	printf("%d", a-b);
}
		return 0;

}
