#include<stdio.h>
#include<string.h>
#include<ctype.h>

void strToUpper(char* name){
	int j;
	for(j = 0; j < strlen(name); j++){
			if(islower(name[j])){
				name[j] = toupper(name[j]);
			}
		}
}

int main(){
 	char names[3][20], nums[3][20];
	char searchName[20];
	int i = 0, j;
	int flag;

	for(i = 0; i < 3; i++){
		printf("Enter name %d: ", i+1);
		gets(names[i]);
		strToUpper(names[i]);
		printf("Enter number: ");
		gets(nums[i]);
	}

	while(1){
		printf("Enter name to search(exit for exit): ");
		gets(searchName);
		if(!strcmp(searchName, "exit")){
			break;
		}
		strToUpper(searchName);
		flag = 0;
		for(i = 0; i < 3; i++){
			 
		}
		if(!flag){
			printf("NOT FOUND\n");
		}
	}
}
