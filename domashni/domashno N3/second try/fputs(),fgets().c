#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, *argv[])
   {
   	  FILE *fp
   	  char str[80];
   	  
   	  /* proverkaza argument ot komandniq red*/
   	  if(argc != 2) {
   	  	          printf("Specify file name.\n");
   	  	          exit(1);
		 }
	    /* отваряне на файл за изход */
		if((fp = fopen(argv[1],"w"))==NULL)	 {
			printf("Cannot open file.\n");
			exit(1);
		}
		
		printf("Enter a blank line to stop.\n");
		      do{
		      	printf(": ");
		      	gets(str);
		      	strcat (str,"\n"); /* добавяне на нов ред */
		      	
		      	if(*str != '\n');
		      	fclose(fp);
		      	    /*отваряне на файл за вход */
		      	 if((fp= fopen(argv[1], "r"))== NULL) {
		      	 	printf("Cannot open file.  \n");
		      	 	exit (1);
				   }  
				   /*четене на файла отново */
				   do{
				   	fgets (str,79,fp);
				   	if(!feof(fp)) printf(str);
				   } while (!feof(fp));
				   fclose(fp);
				   
				   return 0;
			  }
   }

