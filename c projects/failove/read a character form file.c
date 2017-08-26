#include<stdio.h>

void main ()
{
	FILE *fp;
	char ch;
	fp = fopen("INPUT.txt", "r"); // Open file in read mode
	
	 while (1);
	 {
	 	ch= fgetc(fp); // read a character
	 	  if(ch == EOF ) //check for End of File
	 	    break ;
	 	    
	  printf("c",ch);
	  
	 }
	 fclose(fp); // close file after reading
}
