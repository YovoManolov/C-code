#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	 char str[80] = "this is a file system test.\n";
	 FILE *fp;
	 char *p;
	 
	 int i;
	 
	 /*Otvarq myfile za izhod*/
	 if((fp = fopen("myfile","w"))==NULL){
	 	printf("Can not open file. \n");
	 	exit(1);
	 }
	/*zapisva str na diska*/
	p = str;
	while(*p)
	 {
	 	if(fputc(*p,fp)== EOF)
	 	{
		printf("Error writing file.\n");
	 	exit(1);
	   }
		p++;
	 }
	 fclose(fp);
	 
	 /*otvarq myfile za vhod*/
	 if((fp = fopen("myfile","r"))==NULL)
	 {
	 	printf("cannot open file.\n");
	 	exit(1);
	 	
	 }
	 /*chete otnovo faila*/
	 for(;;) {
	 	i = getc(fp);
	 	if(i == EOF) break ;
	 	putchar(i);
     	 }
    fclose(fp);
    return 0;
}

