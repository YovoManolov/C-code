#include <stdio.h>
#include <stdlib.h>

float stingToFloat(char *num);

int main (void){
            char num [50];
			gets(num);
		    
	   printf("that is float : %f \n", stingToFloat(num));
	   
	   return 0;
}



float stingToFloat(char *num) {
	float fnum;
	
	fnum = atof(num);
	
	return fnum;
}
