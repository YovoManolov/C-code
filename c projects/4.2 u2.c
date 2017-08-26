#include<stdio.h>

void f1 (void), f2 (void);

int main (void)
{
	f1();
	return 0;
}
void f1(void)
{
	int count ;
	
	for( i=0;i<10;i++) f2 ();
	
}
void f2 (void)

{
	int count;
	
	for (count=0;count<10;count ++) printf("%d",count);
		
}
