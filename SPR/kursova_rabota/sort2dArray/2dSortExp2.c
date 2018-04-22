#include <stdio.h>

void printJustIds(){

}

int main(int argc , char *argv[])
{
	int i ,j,swap;
	int **arr;

	 x = malloc(5 * sizeof *x);
	 for (i=0; i<5; i++)
	 {
	   x[i] = malloc(2 * sizeof *x[i]);
	 }
	 for(i = 0 ;i<5 ;i++){
	 	arr[i][0] = 2; //hardcode 2 for id 
	 }

	 arr[1][0] = 2;
	 arr[1][1] = 4;
	 arr[1][2] = 
	 arr[1][3]
	 arr[1][4]

	printf("Before sorting\n");
	for ( i = 0 ; i < 5; i++ ) {
       for(j=0; j<2; j++) {
         printf ( "%d \t", arr[i][j] ) ;     //printing sorted array
       }
       printf("\n");
    }


	for(i=0; i < 5; i++) {
	    for (j = i+1; j < 5; j++) {
	       if(arr[i][1] > arr[j][1]){
	           swap = arr[i][1];
	           arr[i][1] = arr[j][1];
	           arr[j][1] = swap;
	       }
	    }
	 } 

    printf("After sorting\n");

	for ( i = 0 ; i < 5; i++ ) {
       for(j=0; j<2; j++) {
         printf ("%d \t", arr[i][j] ) ;     //printing sorted array
       }
       printf("\n");
    }

	return 0;
} 



