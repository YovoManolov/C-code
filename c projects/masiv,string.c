#include<stdio.h>
#include<string.h>

 int main() {
 	char string1[100];
 	int len,i,a;
 	printf("Enter string from Kayboard : \n");
 	scanf("%s",string1);
 	len = strlen(string1);
 	a = len -1;
 	i = 0;
 	while (i<=a) {
 		if(i<a){
 			printf("%c%c",string1[i],string1[a]);
		 }
		 else {
		   printf("%c",string1[i]);
		 }
		 i++;
		 a--;
	}
 	return 0;
 }

