# include<stdio.h>
/* 1 . Writes  Character onto the stream .
 2  it return value is character written on  stream
 3. IF any error Occures then it returns EOF
*/
int main (void)
{
	char msg[] = "hellon";
	int i = 0 ;
	
	while (msg[i])
	       putc(msg[i++],stdout);
	       
   return 0;
}

Output :
	   Writes "Hello" Word to file Character by Character 
	   Diagram :
