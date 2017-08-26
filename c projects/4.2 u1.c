# include <stdio.h>
void f1 (void);

int count; 
/*global coubnt*/
int main (void)
{	
count =10;
f1 ();
printf("count in main():  %d\n", count);

return 0;
}
void f1 (void){

int count; /* локална count */

count = 100 	;
printf("count in f1(): %d\n", count);
}

