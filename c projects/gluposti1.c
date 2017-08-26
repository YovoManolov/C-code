#include<stdio.h>
int letter_counter (char word[50]);

int letter_counter (char word[50]) {
	int a = 50 , counter = 0 ,i = 0;
	for(i ; i< a ; i++){
		if(word[i] != '\0'){
		  counter++ ;	
		}
		else break ;
	}
	return counter;
}
int main () {
	char charArray [50];
	int i  = 0;
	printf("Enter char : \n");
		for(i ;i < 50 ; i++){
			scanf("%c", &charArray[i]);
		}
    char * adrOfCharArray = charArray;
	printf("%d" , letter_counter(adrOfCharArray));
	return 0;
}
