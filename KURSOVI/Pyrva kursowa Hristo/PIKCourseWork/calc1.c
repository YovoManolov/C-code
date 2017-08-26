#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

char numbersExtracting (char *mathexp,char *num);

	int main() {
	
			char mathexp[100];
			 char num [95];
		    printf("Enter your math expression: \n" );
		    gets(mathexp);
		    
		   printf ("only the numbers are : %s " , numbersExtracting(mathexp,num));
    return 0;
    } 
    
    
 char numbersExtracting (char *mathexp,char *num){
			int mat_exp_len,i ;
			mat_exp_len = strlen(mathexp);
			
			for(i=0;i<mat_exp_len;i++){
					if (!(mathexp[i] == ' '||'+'||'-'||'/'||'*')){
						num[i] = mathexp[i];
					}
			}
return num;		
}
/*float stingToFloat(void){
	char num [50];
	printf("Enter number \n")
			gets(num);
		float fnum;
	
	fnum = atof(num);
	
	return fnum;
}
*/



