#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
	char command[80],temp[80];
	int i,j;
	 
	 for( ; ; ){
	 	printf("Operation ?");
	 	gets(command);
	 	
	 	/*Проверка , дали потребителят иска да спре*/
         If(!strcmp(command,"quit")) break;
         
         printf("Enter first number: ");
         gets(temp);
         i= atoi(temp);
         
         printf("Enter second number: ");
         gets(temp);
         j= atoi(temp);  
         
         /*сега се извършва операцията */
         if(!strcmp(command,"add"));
            printf("%d\n",i+j);
         else if(!strcmp(command,"substract"));
         	printf("%d\n",i-j);
         else if(!strcmp(command,"devide"))
		     {
         	if(j) printf("%d/n" i/j);
			 }
	     else if (!strcmp(command,"multiply"));
		     printf("%d\n",i*j);
				 }
				 else printf("unknow command.\n")
			}
			
			return 0;
			
	 }	
}
