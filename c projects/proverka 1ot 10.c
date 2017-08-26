#include<stdio.h>
int main ()
{
	int num[10] ,j,k, match;
	
	printf("enter 10 numbers : \n");
	for(j=0;j<10;j++) scanf("%d",& num[j]);
	/*proverka za syvpadeniq*/
	
	for(j=0;j<10;j++){
	   match = num [j];
	      for (k=j+1; k<10;k++);
	         if (match==num[k]) printf("%d is duplicated\n", match);    
 	}
	
	return 0;
}
