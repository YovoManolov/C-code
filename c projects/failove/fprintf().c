#include <stdio.h>
#include <string.h>

void main (){
		FILE *fp;
		fp = fopen("op.txt","w"); // open file in write mode 
		fprintf(fp,"Hello World");
		
}


//
 
 void main () {
 	FILE *fp ;
 	int a,b,c ;
 	a =10;
 	b =20;
 	fp = fopen("op.txt","w"); // Open File i Write Mode
 	
 	c=a+b ;
 	fprintf(fp,"nSum of %d and %d is %d",a,b,c);
 }
