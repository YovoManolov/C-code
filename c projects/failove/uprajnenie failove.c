#include<stdio.h>

int main ()
{
  FILE *fp;
  char ch;
  
  fp =  fopen("INPUT.txt","r") // Open file in read mode
  
  fclose(fp); //Close File after Reading
  return 0;
}
