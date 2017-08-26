#include <stdio.h>

int main(){
	char masiv[200];
	int i;
	printf("wyvedi bykvi do 100 simvola sydyrvashti space-ove :\n\n\n\n\n");
	scanf("%c",&masiv[100]);
	
	for(i=0;i<200;i++){
		if(masiv[i]==' ' || masiv[i]== '.'){
			masiv[i] = '\n';
		}	
	}
	printf("preraboteniqt masiv e :... %c", masiv[200]);
	return 0 ;
}
