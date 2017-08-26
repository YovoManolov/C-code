#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main ()
{
	 int val;
	 char str[20];
	 
	 strcpy(str,"995473543");
	 val= atoi(str); // prisvoqvane v promenliva val na preobrazuvanata stoinost na string v int
	 printf("string value= %s,Int value = %d\n",str,val);
	 
	 
	 strcpy(str, "tutorialpoint.com");
	val = atoi(str);
	printf("string value = %s,Int value = %d\n",str,val);
	
	return 0;
	
}

