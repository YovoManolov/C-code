//Sizeof
/*chrez izpolzvanetonna sizeof si osigurqvame bezproblemniqt prehod kum druga
sreda*/

#include <stdio.h>
#include <stdlib.h>
int main (void) {
	File *fp;
	 int i ;
	 /*отваряне на файл за изход*/
	 
	 if((fp = fopen("myfile","wb")== NULL) {
	 	printf("Cannot open file .\n");
	 	exit (1);
	 }
	 i= 100;
	 if(fwrite(&i , sizeof(int)),1,fp) != 1 )  {
	 	printf("Write error occured. \n");
	 	exit (1);
	 }
	 fclose (fp);
	 
	 /*otvarqne na fail za vhod*/	 
	 if(fp = fopen ("myfile","rb")==NULL ) {
	 	printf("cannot open file \n" ) ;
	 	exit (1);
	 }
	 if(fread(&i,sizeof i ,l,fp) != 1) {
	 	printf("read error occured.\n");
	 	exit (1);
	 }
	 return 0;
}

