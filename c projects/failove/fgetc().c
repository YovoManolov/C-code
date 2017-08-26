#include<stdio.h>

void main() {
	FILE *fp;
	char ch;
	fp = fopen ("tmp.txt","r");
	printf("Data inside File : ");
	while (1){
		ch= fgetc(fp);
		
		if(ch == EOF)
		break ;
		
		printf( "%c",ch);
	}
	getch ();
}
