
/*
SYNTAX:
 #include<stdio.h>
 int fput(const char *str, FILE*stream);
 fputs : on success returns last character written.
 / on error returns EOF
 str - String to be written on Steam 
  * stream  - File pointer 
*/


#include <stdio.h>
int main (void){
	 /*write a strind to standard ouput*/
	 fputs/* outputs string to a stream,  copies 
	 the null - terminated string s to the given output 
	 stram. it does not append a newline charter,
	  and the terminating 
	 null charter is not copied */("Hello worldn",stdout);
	 return 0;
}
