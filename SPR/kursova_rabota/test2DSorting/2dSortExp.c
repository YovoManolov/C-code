#include <stdio.h>

int main(int argc , char *argv[])
{
	int i ,j;
	int arr[5][2] = {
			{5,2},
			{3,2},
			{4,2},
			{1,2},
			{2,2}
	};

	printf("Before sorting\n");
	for ( i = 0 ; i < 5; i++ ) {
       for(j=0; j<2; j++) {
         printf ( "%d \t", arr[i][j] ) ;     //printing sorted array
       }
       printf("\n");
    }

	int temp,temp1;

	 for(j=1;j<5;j++)
     {
          for(i=0; i<4; i++)
          {
                if(arr[i][0] > arr[i+1][1])
                {
                    temp=arr[i][0];
                    arr[i][0]=arr[i+1][0];
                    arr[i+1][0]=temp;

                    temp1 = arr[i][1];
                    arr[i][1] = arr[1][i+1];
                    arr[i+1][1]=temp1;
                }
          }
     }

    printf("\nAfter sorting\n");

	for ( i = 0 ; i < 5; i++ ) {
       for(j=0; j<2; j++) {
         printf ( "%d \t", arr[i][j] ) ;     //printing sorted array
       }
       printf("\n");
    }

	return 0;
} 