#include<stdio.h>
int main (){
	int *p ,q;
	p =  &q;
	
	q=1;
	
	printf("%p", p);
	
	(*p)++; // сега (q) e inkriminiran a (p) e nepromenen
	printf("%d %p", q,p);
	
	return 0 ;
}


