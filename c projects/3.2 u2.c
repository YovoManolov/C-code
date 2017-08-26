#include <stdio.h>

int main (void){

	int a ,b;
	printf("Insert the first number : ");
	scanf("%d",&a);
	printf("Insert the second number: ");
	scanf ("%d",&b);
	 if(a == b)printf("the numbers must to be different");
	  else if (a == 0 ) printf ("a and b must to be different from 0");
	  else if (b == 0 ) printf ("a and b must to be different from 0");
	  else {
	  printf("%d ",a*b);
	  printf("That is the surface of the rectangle");
      }
	 return 0;
}
