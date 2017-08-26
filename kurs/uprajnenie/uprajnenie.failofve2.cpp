#include<stdio.h>
#include<stdlib.h>

int main (void)
{
	char str [80] = "this is a file sistem test.\n";
	FILE *fp;
	char ch, *p;
	
	// otvarq myfile za izvejdane
	
	if((fp = fopen("myfile","w")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}
	
	/* записва str na diska*/
	
	p = str ;
	while (*p)  {
		if(fputc(*p,fp)== EOF)  {
			printf("Error writing file.\n");
			exit (1);
		}
		p++;
	}
	fclose(fp);
	/*otvarq myfile za vyvejdane*/
	if((fp = fopen("myfile","r"))== NULL )  {
		printf("Cannot open file.\n");
		exit(1);
	}
	// chete otnovo faila 
	for(;;) {
		ch = getc (fp);
		if(ch == EOF) break ;
		putchar (ch) ;  
	}
	fclose(fp);
	return 0;
}
