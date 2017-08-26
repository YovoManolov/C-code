/*Напишете програма създаваща стругктура с 3 побитови полета  a b ,c  а и б по 3 бита 
а ц да е 2 бита присвоете на вссяко от тяг някаква стойност и ги изпишете на екрана*/

#include <stdio.h>
 int main () {
 	struct b_type {
 		int a: 3 ;
 		int b: 3 ;
 		int c: 2 ;
	 } bvar;
 	
 	bvar.a = -1;
 	bvar.b = 3;
 	bvar.c = 1;
 	
 	printf("%d %d %d", bvar.a, bvar.b, bvar.c);
 	
 	return 0;
 }
