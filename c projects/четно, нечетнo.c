#include <stdio.h>

int main (void)
{

int chislo ;
printf("vyvedete chislo : ");

scanf("d%", &chislo);

if (chislo % 2 == 0 ) printf ("tova chislo e chetno");
if(chislo % 2== 1) printf("tova chislo e nechetno");

return 0;
}
