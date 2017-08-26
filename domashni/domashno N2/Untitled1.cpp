 #include<stdio.h>
 #include<stdlib.h>
 int main ()
 {
 	int arr [10];
    int i ,n;
    
    n=10;
    
    srand((unsigned) time(&t));

    for( i = 0 ; i < n ; i++ )
       {
           printf("%d\n", rand() % 100 + 20);
       }
     
     scanf("%d",& arr[i]);
     
     return 0;
     
 }
