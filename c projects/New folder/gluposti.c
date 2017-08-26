#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	char fileName [100] ;
	printf("Input file name(.TXT): ");
			gets(fileName);
			
			if(toupper(fileName[strlen(fileName) - 1]) == 'T' && toupper(fileName[strlen(fileName) - 2]) == 'X' && toupper(fileName[strlen(fileName) - 3]) == 'T' &&
            (fileName[strlen(fileName) - 4] == '.'))
            
            {
               printf("RIGHT \n ");
			}

		
		else
        {
			printf("wrong \n");
		
        }
        
     return  0;   
}

