/*1.  
Напишете програма, която репрезентира калкулатор. За вход получава 
стринг с израза, който трябва да бъде пресметнат
 и изкарва на екрана резултата. Операндите са единствено цели
  числа от тип unsigned, а позволените оператори са +, -, * и %.
Примери: 
Вход: 17 + 4 / 2
Изход: 17 + 4 / 2 = 19

Вход: 17 + +4 / 2
Изход: Expression Error

*/

/*всяко число се вкарва чрез отделен стринг , минава
през ф-я,прави се проверка за оператори +, -, * и % */

//PROWERKA RED NA DEISTWIQ 
//PROWERKA 2 OPERATORA 

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

//float stingToFloat();

int main(){
			char mathexp [100], num1[90], num2[90], num3[90];	
			int mat_exp_len , counter,i,b = 0,c = 0;
			
		    printf("Enter your math expression: \n");
	    	gets(mathexp);
			mat_exp_len = strlen(mathexp);
			
		for(i=0;i<mat_exp_len;i++) {
		    if (mathexp[i]>='0'&& mathexp[i]<='9'){
		    	num1[i] = mathexp[i] ;
		    	counter++;
 			}
		}
		counter += 1;
		printf("num 1 is : %s \n",num1);
		
		
		for(i=counter;i<mat_exp_len;i++) {
		    if(mathexp[i]>='0'&& mathexp[i]<='9'){
		    	num2[b] = mathexp[i] ;
		    	counter++;
 			}
 			b++;
		}
		counter += 1;
		printf("num 2 is : %s \n",num2);
		
		
		for(i=counter;i<mat_exp_len;i++) {
		    if(mathexp[i]>='0'&& mathexp[i]<='9'){
		    	num3[c] = mathexp[i] ;
 			}
 			c++;
		}
		printf("num 3 is : %s \n",num3 );
		
		return 0;
    }
 

/*float stingToFloat(void){
	char num [50];
	printf("Enter number \n");
			gets(num);
		float fnum;
	
	fnum = atof(num);
	
	return fnum;
}
*/





