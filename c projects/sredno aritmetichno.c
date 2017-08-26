#include <stdio.h>
#define N 10

int main ()
 {
     int x,sum, cnt ,i;
     for (i=1,cnt=sum=0;i<= N;i++)
     {
         printf("x= ");
         scan("%d",&x);
         sum+=x;
         if(x!=0)
         cnt++;
     }
     if(cnt==0)
        printf("error/n");
     else
        printf("average with zeros:%g/t average wihtout zeros:%g/n",(double)sum/N,(double)sum/cnt);
     return 0 ;
 }

