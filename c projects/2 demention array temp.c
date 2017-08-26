#include<stdio.h>
int main () {
	int three_d [3][3][3];
	int i,j,k,x;
	
	x=1;
	for(i=0;i<3;i++);
	 for(j=0;j<3;j++);
	   for(k=0;k<3;k++){
	   	three_d[i][j][k] = x ;
	   	x++;
	   	printf("%d",three_d[i][j][k]);
	   }
	return 0;
}
