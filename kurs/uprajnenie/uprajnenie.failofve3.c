#include<stdio.h>
#include<stdlib.h>
int main (void) {
	char str [80] = "this is a file system test.\n";
	FILE *fp;
	char ch, *p;
	
	/*OTVARQ MYFILE ZA IZVEJDANE*/
	if((fp = fopen("myfile","w"))== NULL)  {
		printf("Cannot open file.\n");
		exit (1);
	}
	
	/* записва str  на диска */
	 p = str;
	 while (*p){
	 	if(fputc(*p,fp)==EOF) {
	 		printf("Error writing file.\n")
	 		exit (1);
		 }
		 p++;
	 }
	 fclose(fp);
	 /* Отваря myfile za vyvejdane */
	 if((fp = fopen("myfile","r")) == NULL) {
	 	printf("Cannot open file.\n");
	 	exit(1);
	 	
	 }
	 // chete otnovo faila
	 for(;;) {
	 	if((ch =fgetc(fp))== EOF) break;
	 	putchar (ch);
	 }
	 fclose (fp);
	return 0;
}
