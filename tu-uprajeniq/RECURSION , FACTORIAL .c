/*Напишете функция ,fact (),използваща рекурсия за изчисление на факториела
на целочисления си аргумент. Нека тя го връща като резултат.Демострирайте употребата и в програма.
*/


#include <stdio.h>

int fact (int b);
int c ;
int fact (int b){
	if(b == 1) return 1;
	else return b * fact(b-1) = c;
}

int main (void) {
	int b;
	printf("Enter the number for factorial : " );
	scanf("%d", &b);
	printf("Factorial of number X is %d", c);
	return 0;
}
