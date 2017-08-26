/*programa koqto kopira tekstov fail.neka potrebitelqt da 
zadawa imenata na dwata faila i komandniqt red . programata 
trqbwa da se preobrazuva  wsichki malki bukwi v glavni*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main (int argc,char  argv[]){
	file *from, *to;
	 char ch;
	 /*proverka za veren broi argumenti w komandniq red*/
	 
	 inf (argc!=3) {
	 	printf("Usage :coppy <source> <destination>\n");
	 	exit (1);
	 }
	/*otvarqne na faila izgtochnik*/
	if((from=fopen(argv[1],"r"))== NULL){
		printf("Cannot open source file.\n");
		exit(1);
	}
	/*ptvarqne na faila cel*/
	if((to = fopen(argv[2],"w"))== NULL) {
		printf("Cannot open destination file.\n");
		exit(1);	
	}
	
	/*kopirane na faila*/
	while (!feof(from)) {
		ch = fgetc(from);
		if(!feof(from)) putc(toupper (ch),to);
		}
		fclose(from);
		fclose(to);
		
		return 0;
}

