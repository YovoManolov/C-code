#include <stdio.h>

void printJustIds(){

}

int main(int argc , char *argv[])
{
	int i ,j,swap;

	int arr[5][2] = {
			{2,5},
			{2,3},
			{2,4},
			{2,1},
			{2,2}
	};

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



