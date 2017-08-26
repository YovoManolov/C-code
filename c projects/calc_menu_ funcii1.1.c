#include<stdio.h> 
#include <math.h>

int menu(){
	int choice ;
	 printf("|_______________MENU________________|\n");
     printf("|____1.Add _________________________|\n");
     printf("|____2. Substract __________________|\n"); 
     printf("|____3. Divide _____________________|\n");
     printf("|____4. Multiply____________________|\n");
	 printf("|____5. Find sqare root ____________|\n");
	 printf("|____6. Rase to power _____________ |\n");
     printf("|____7. Exit________________________|\n");
	
	
 	do{
		printf("Enter your choice : \n");
		//4istene na bufera
		fflush(stdin);
		scanf("%d" ,&choice  );
	}while(choice <1 || choice > 7);
  
   return choice ;
}

float add (float num1, float num2) {
	float add; 
	add = num1+num2;
	return add;
}
float substract(num1,num2) {
	float substract; 
	substract = num1 * num2;
	return substract;
}

float multiply (float num1, float num2) {
	float multiply; 
	multiply = num1 * num2;
	return multiply;
}

float divide(float num1, float num2) {
	float divide; 
	divide = num1 /num2;
	return divide;
}

int main() {
	 
switch(menu()) {
	 float num1,num2,sum,diference,result1,result2;
        case 1:
        		printf("Enter 1st numbers to add\n");
	            scanf("%f" ,&num1) ; 
	            printf("Enter 2nd numbers to add\n");
			    scanf("%f" ,&num2) ; 
	            sum= add(num1,num2);
	            printf("sum = %f", sum);
            //printf("%.1f + %.1f = %.1f",num1, num2, num1+num2);
            break;
        case 2:
            printf("Enter 1st numbers to Substract\n");
	            scanf("%f" ,&num1) ; 
	            printf("Enter 2nd numbers to Substract\n");
			    scanf("%f" ,&num2) ; 
	            diference = substract(num1,num2);
	            printf("Substract= %f", diference);
            break;
        case 3:
            printf("Enter 1st numbers to Divide\n");
	            scanf("%f" ,&num1) ; 
	            printf("Enter 2nd numbers to Divide\n");
			    scanf("%f" ,&num2) ; 
	            result1 = divide(num1,num2);
	            printf("Divide = %f", result1 );
            break;
        case 4:
            printf("Enter 1st numbers to Multiply\n");
	            scanf("%f" ,&num1) ; 
	            printf("Enter 2nd numbers to Multiply\n");
			    scanf("%f" ,&num2) ; 
	            result2 = multiply(num1,num2);
	            printf("Multiply= %f", result2);
            break;
        case 5:
            printf("%.1f / %.1f = %.1f",num1, num2, num1/num2);
            break;
        case 6:
            printf("%.1f / %.1f = %.1f",num1, num2, num1/num2);
            break;
        default:
            printf("Have a good day!!!");
            break;
    }
	
	return 0;
}

