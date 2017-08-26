#include<stdio.h>
#include<conio.h>
int main(){
  char a[10][10]={"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
  char b[10][10]={"ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINTEEN"};
  char c[10][10]={"TEN","TWENTY","THIRTY","FOURTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINTY"};
  char d[20][20] ={"ONE HUNDRED ","TWO HUNDRED","THREE HUNDRED","FOUR HUNDRED","FIVE HUNDRED",
  "SIX HUNDRED","SEVEN HUNDRED","EIGHT HUNDRED","NINE HUNDRED"};
  int no,t;
    printf("Enter the number");
    scanf("%d",&no);
    printf("tt");
  
  if(no<9999){
        
		if(no>1000){
               t=no/1000;//namira purva cifra 
                no=no%1000;
                printf("%s THOUSAND",a[t-1]);
                   }
                   
        if(no>=100 && no<999){
                t=no/100;
                printf("%s ",d[t-1]);
                          
						 }
                   
        if(no>100) {
              t=no/100;
               no=no%100;
			   printf(" %s HUNDRED AND ",a[t-1]);
                    }
                    
        
		if(no>=10 && no<20){
           t=no/10;
           printf("%s",b[t-1]);
                          
						   }
        
		if(no>19 && no<=100){
		   t=no/10;
		   no=no%10;
		   printf("%s",c[t-1]);

                            }
        
        if(no<10){
		     printf(" %s",a[no-1]);
                 }

            }

        else
        printf("ttEnter the small number");
        getch();

   }


 
