#include <stdio.h>

int main () {
	int i, num;
	int result;
	
	printf("Input a number : ");
	scanf("%d", &num);
	
	
	result  = calculateSum (num);
	printf("/n Sum of Number From 1 to %d : %d",num,result);
	
	return (0);
}

int calculateSum (int num) {
	int res;
	if (num == 1) {
		return (1);	
	}else {
		res = num + calculateSum (num - 1);
		
	}
	return (res );
}
