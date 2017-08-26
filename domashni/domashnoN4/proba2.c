#include<stdio.h>

	int main()
	{
		char mathexp [100]; 
		int i ,counter =0;
		printf("Enter your math expression: \n" );
		gets(mathexp);
		
     		for(i;i<100;i++) {
		    while (mathexp[i] == '0'||mathexp[i] ==1 ||mathexp[i] == 2||mathexp[i] == 3
			||mathexp[i] == 4||mathexp[i] == 5||mathexp[i] == 6||mathexp[i] == 7||mathexp[i] == 8||mathexp[i] == 9){
		    	counter++ ;
 			}
		}
		
		printf("caunter value : %d \n", counter);
     	return 0;
	}
