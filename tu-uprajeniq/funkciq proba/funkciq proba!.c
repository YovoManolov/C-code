#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int return_counter(char *str1_1, int i, int counter0);
int return_counter(char *str1_1, int i, int counter0) {
	        for (i=0; i<30000 ;i++) {
            	while(str1_1[i] != '*' /*__ascii cod for (*) ___ */ ){
            		counter0 ++; // Дължината на стринга до звездичката .
            	 }	
			}
			
return counter0;
}

int main() {
	    FILE *fptxt ;
		char str1_1 [30000] ,str1_2 [30000];
		int i = 0 ,counter0 = 0 ;
		if((fptxt = fopen("text.txt ","wb")==NULL)) {
	     	printf("Cannot open file.\n");
	    	exit(1);
            }
            printf("Enter text from kaybord that contains a star :");
            scanf("%s", &str1_1[30000]);
		  strncpy(str1_2,str1_1, return_counter());
		  fputs(str1_2,fptxt);
		  
		  fclose (fptxt);
}
