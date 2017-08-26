
#include <stdio.h> 
#include <string.h> 

int main(){
	int  mat_exp_len,counter = 0 , b = 0 ;
	int i=0;
	char mathexp[300] ,num2[100];

	 printf("Enter your math expression: \n" );
		    gets(mathexp);
            mat_exp_len = strlen(mathexp);
		    	printf(" math expression lenght: %d\n" ,mat_exp_len);    
		    	
		for(i;i<mat_exp_len;i++) {
		    if (mathexp[i]>='0'&& mathexp[i]<='9'){
		    	counter ++;
 			}
		}
		 	 
			  printf("caunter value : %d \n", counter );	
return 0; 	
}
