# include <stdio.h>
int main ()
{
	int i,j;
	
	printf("Enter first number:  ");
	scanf("%d", &i);
	printf("Enter second number: ");
	scanf("%d", &j);
	
	/*операции за сравнение*/
	printf("i<j %d\n",i<j);
	printf("i<=j %d\n",i<=j);
	printf("i ==j %d\n",i==j);
	printf("i> j %d\n",i>j);
	printf("i>=j %d\n",i >= j);
	
	/*logic operations */
	printf("i && j %d\n",i && j);
	printf("i || j %d\n",i || j);
    printf("!i !j %d\n", !i , !j);
    
	return 0 ;
	
	}
