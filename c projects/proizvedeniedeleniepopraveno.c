
#include<stdio.h>
int main(void)
{

	double a, b, c;
	printf("vyvedete 2 chisla");
	printf("Enter first number: ");
	scanf_s("%d", &a);
	printf("Enter second number: ");
	scanf_s("%d", &b);

	printf("enter third number :1 for multiply 2 for divide ");
	scanf("%d", &c);
	if (c == 1)
	{
		printf("answer is : %d.", a*b);
	}
	else 
	{
		printf("answer is : %d.", a / b);
	}
	return 0;
}
