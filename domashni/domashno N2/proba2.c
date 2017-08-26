#include<stdio.h>
#include<string.h>
int main (){
	char stri[]= " i ";
	char str1_9_1[]= "edno";
   char str20_29[]="dvadeset";
	
	strcat(str20_29, stri);
	strcat(str20_29, str1_9_1);
    printf("%s",str20_29);
       
    return 0;
	
}
