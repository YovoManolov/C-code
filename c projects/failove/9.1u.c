/*programa izvejdashta sud na tekstov fail zadadena v koandniq red -red po red
sled izvejdaneto na vseki red iziskvajte potwyrjdenie na izvejdaneto na sledvashtiq*/

#include<stdio.h>
#include <stdlib.h>
#include <cype.h>

int main(int argc, char *argv[])

{
	FILE*fp;
	char str[80];
	/*proverka dali e zadadeno ime na fail*/
	
	if(argc!=2){
		  printf("file name missing.\n");
		  exit (1);
	}
	if(!feof(fp))  {
		fgets(str,79,fp);
		if(!feof(fp)) printf("%s",str);
		pritnf(".....More? (y/n) ");
		if(toupper (getchar()) == 'N') break;
		printf("\n");
		
	}
	fclose (fp);
	return 0;
 } 
