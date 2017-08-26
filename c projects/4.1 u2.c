# include <stdio.h>
 
int main(void)
{
	unsigned long int distance;
	printf("Enter distance : ");
	scanf("%lu", &distance);
	printf("%ld seconds" , distance / 186000);
	
	return 0;
}
