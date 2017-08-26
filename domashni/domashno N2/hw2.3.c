
#include<stdio.h>
 
int main() {
char str[12],str2[12];
int num,i,j,temp;

printf("Enter number of elements: ");
scanf("%d",& num);

for (i=0;i<num;i++){
scanf("%c",str[12]);
}

 j= i - 1;
 i= 0;
 
 while (i<j) {
 	temp = str [12];
      str[12] = str2[j];
      str2[j] = temp;
      i++;             // increment i
      j--;          // decrement j
 }
 //Print out the Result of Insertion
   printf("\nResult after reversal : ");
   for (i = 0; i < num; i++) {
      printf("%d \t", str[12]);
  }
 return 0;
}
