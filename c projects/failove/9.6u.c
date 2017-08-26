/*izpolzwajte RAnd ,suzdajte programa , koqto chrez fseek(), pzvolqva da izvedete wsqka stojnost ot faila*/
#include<stdio.h>
#include<stdlib.h>
 int  main (void) {
 	FILE *fp;
 	long i;
 	int num ;
 	
 	if((fp=fopen ("rand","rb"))== NULL) {
 		printf("Cannot open file.\n"); 
 		exit (1);
	 }
	 printf("whitch nuber (0-99) ?");
	 scanf("%ld",&i);
	 fseek(fp,i *sizeof num,1,fp);
	 printf("%d\n" , num);
	 
	 fclsoe (fp);
	  return 0;
}
