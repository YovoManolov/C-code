 #include<stdio.h>
 int main(void){
 	FILE *fp;
 	fp =  fopen("op.text", "w");
 	fputs("hallo worldn", fp);
 	return 0;
 }
 
 /*
 Output:
 	 1: op.txt FIle is opened into write mode
 	 2 : Write :"hello world" to op .txt file
