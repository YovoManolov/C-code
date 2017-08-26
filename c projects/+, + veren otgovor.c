# include <stdio.h>

int main (void)

{
	int answer;
	printf("What is 10 +14");
	scanf("%d" ,&answer);
	
	if (answer == 10+14 ) printf ("right !");
	else  {
	printf(" Sorry you are wrong.");
	printf("The answer is 24");
	}
  return 0 ;
	
}
