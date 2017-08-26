#include<stdio.h>
#include <stdlib.h>

int main (void)
{
	char str[80]= "this is a file sistem test.\n";
	FILE *fp;
	char *p;
	int i;
	
	/*отваря myfile за изход*/
	if((fp = fopen("myfile","w"))==NULL){
		printf("Cannot open file.\n");
		exit (1);
			}
			//zapisva str na diska
			p = str;
			while(*p) {
				if(fputc(*p,fp)==EOF){
					printf("Error writing file.\n");
					exit(1);
				}
				p++;
			}
			fclose(fp);
			/*отваря myfile за вход*/
			if((fp = fopen("myfile","r"))==NULL){
				printf("Cannot open file.\n");
				exit(1);
			}
			/*чете отново файла*/
			for(;;) {
				i = fgetc(fp);
				if(i==EOF)break;
				putchar (i);
			}
			fclose(fp);
			return 0;
}


