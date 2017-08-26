#include <stdio.h>
int main(){
	char rev [50], temp;
	int a,b=0;
	
	
	printf("enter the string: ");
	gts(rev);
	
	a=0;
	b = strlen(rev)-1;
	
 while (a<b){
 
     temp =rev[a];
     rev[a]=rev[b];
     rev[b]=temp;
     
     a++;
     b--;
}
printf("the  reverse string is: %s",rev);

return 0;
}
