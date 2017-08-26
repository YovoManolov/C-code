# include <stdio.h>

int main (void)
{
	int answer , count;
	int again;
	
	for(count=1; count<11 ;count++) {
		printf("what is %d + %d?",count ,count );
		scanf("%d", & answer) ;
		
		if (answer == count+count) printf("Right!\n");
		else { 
		printf("sorry ,you're wrong\n");
		printf("Try again.\n");
		
		printf("\n What is %d + %d ",count,count);
		scanf("%d",&answer);
		/* גדנאהום If */
		if (answer== count+count) printf("right!/n");
		else printf("wrong, the answer is %d\n",
		count+count);
	
		}
		
	}
	return 0;
}
