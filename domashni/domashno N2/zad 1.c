 #include<stdio.h>
 #include<stdlib.h>
 #define _CRT_SECURE_NO_WORRINGS
 int main ()
 {
 	int arr [10];
    int i ,n,avg=0;
    time_t t;

    
    n=10;
    
    srand((unsigned) time(&t));

    for( i = 0 ; i < n ; i++ ){
           printf("%d\n", rand() %80 + 20);
       }
       
    for (i=0;i<10;i++) {
	   avg=avg+arr[i];
       printf("Average value is :%d\n", avg/10);
    }
     return 0;
     
 }
