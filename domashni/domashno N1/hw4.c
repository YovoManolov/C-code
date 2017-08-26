 # include <stdio.h>
 # include <math.h> 
double a , ostatyk;
double f1 ();
double f2 ();
int main(double a)
{
	printf("enter a number");
	scanf( "%d", & a);
	if(a<0) printf("%d",a);
	if(a=0) printf("%d",a);
	if( a=1 ) printf("%d",a);
	if (1<a<10) f1();
	if (10<=a<=100) f2();
	if (a>100) printf("Korenyt na chisloto %d e %d\n", sqrt(a));
	
	return 0 ;
	
	}
double f1 (){ 
for (a=0;a<10;a++) {
	printf("Factorial of %d is %d\n", a, factorial(a));
}
   /*  if( a ==2 )
     {
      printf("%d/n ", 1*2) ;
     }
      if( a ==3 ) ;
 
    {
     printf("%d/n", 1*2*3); 
    }
     if( a ==4 ) ;
    {
     printf("%d/n", 1*2*3*4);
    }
     if( a ==5 ) ;
     {
      printf("%d/n", 1*2*3*4*5 );
      }
    if( a ==6 ) ;
     {
     printf("%d/n", 1*2*3*4*5*6);
     }
  
     if( a ==7 ) ;
    {
      printf("%d/n", 1*2*3*4*5*6*7);
     }
     if( a ==8 ) ;
     {
     printf("%d/n", 1*2*3*4*5*6*7*8);
     }
    if( a ==9 ) ;
    {
     printf("%d/n", 1*2*3*4*5*6*7*8*9);
    }
    */
    
}
 double f2 () {
  printf("%d\n",a%2 = ostatyk);
  if (ostatyk == 1) printf("nechetno/n");
    else if (ostatyk == 0) printf("chetno/n");
 }
 
