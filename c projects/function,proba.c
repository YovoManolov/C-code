#include <stdio.h>
#include <string.h>

ime3_f(char *ime1, char*ime2,char *ime3);

int main(){
    char ime3 [50];
	char ime1[10] = {ivan_obicha};
	char ime2[8] = {Dragan};
	
	printf("ime 1 + ime 2 = %c ", ime3_f());
}
 

char ime3_f(char *ime1, char*ime2,char *ime3){
	strcpy(ime3,ime1);
	strcat(ime3,ime2);
	
	return *ime3;
}

