#include <stdio.h>
 
int main ()
{
   int a = 100;
   
   for( a; a <= 100; a = a - 1 )
   {
      printf("value of a: %d\n", a);
   }
 
   return 0;
}
