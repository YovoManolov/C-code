#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void symbolsInComments(FILE* inputStream, FILE* outputStream);
void symbolsInIdentificators(FILE* inputStream, FILE* outputStream);
int fileToFile(void);
int fileToScreen(void);
int screenToFile(void);
int screenToScreen(void);
void getFileName(char* fileName, int mode);

int menu(){
	int i;
	
	printf(" __/MAIN MENU\\_______________________\n");
	printf("|                                    |\n");
	printf("|   1. FILE TO FILE                  |\n");
	printf("|   2. FILE TO SCREEN                |\n");
	printf("|   3. KBRD TO FILE                  |\n");
	printf("|   4. KBRD TO SCREEN                |\n");
	printf("|   0. EXIT                          |\n");
	printf("|____________________________________|\n");
	do{
		printf("SELECT OPTION: ");
		fflush(stdin);
		scanf("%i", &i);
	}while(i < 0 || i> 4);

	return i;
}

int main(void){

	while(1){
		system("cls");
		switch(menu()){
			case 1: fileToFile();
				break;
			case 2: fileToScreen();
				break;
			case 3: screenToFile();
				break;
			case 4: screenToScreen();
				break;
			default: 
				exit(0);
		}
		system("pause");
	}
}

void getFileName(char* fileName, int mode){
	while(1){
		fflush(stdin);
		if(mode == 1){
			printf("Input file name(.C): ");
			gets(fileName);

			if(fileName[strlen(fileName) - 2] == '.' && toupper(fileName[strlen(fileName) - 1]) == 'C'){
				return;
			}
		}else{
			printf("Output File: ");
			gets(fileName);
			return;
		}
	}
}

int fileToFile(void){
	char inputFileName[256], outputFileName[256];
	FILE *inputStream, *outputStream;

	getFileName(inputFileName, 1);
	if(!(inputStream = fopen(inputFileName, "r"))){
		fprintf(stderr, "Error opening file!\n");
		return -1;
	}

	getFileName(outputFileName, 2);
	if(!(outputStream = fopen(outputFileName, "w"))){
		fprintf(stderr, "Error opening file!\a\n");
		return -1;
	}

	symbolsInComments(inputStream, outputStream);
	rewind(inputStream);
	symbolsInIdentificators(inputStream, outputStream);
	fclose(inputStream);
	fclose(outputStream);

	printf("Results saved to \"%s\".\n", outputFileName);
	return 0;
}

int fileToScreen(void){
	char inputFileName[256];
	FILE* inputStream;

	getFileName(inputFileName, 1);
	if(!(inputStream = fopen(inputFileName, "r"))){
		fprintf(stderr, "Error opening file!\n");
		return -1;
	}

	symbolsInComments(inputStream, stdout);
	rewind(inputStream);
	symbolsInIdentificators(inputStream, stdout);
	fclose(inputStream);

	return 0;
}

int screenToFile(void){
	char outputFileName[256];
	FILE *outputStream, *tempStream;
	char str[999];

	tempStream = fopen("temp.tmp", "w");
	fflush(stdin);
	printf("Enter text below, to exit type \"save\" on new line\n");
	printf("------------------------------------------------------\n");
	while(1){
		gets(str);
		if(!strcmp(str, "save")){
			fclose(tempStream);
			system("pause");
			tempStream = fopen("temp.tmp", "r");
			break;
		}
		fprintf(tempStream, "%s\n", str);
	}

	getFileName(outputFileName, 2);
	if(!(outputStream = fopen(outputFileName, "w"))){
		fprintf(stderr, "Error opening file!\a\n");
		return -1;
	}

	symbolsInComments(tempStream, outputStream);
	rewind(tempStream);
	symbolsInIdentificators(tempStream, outputStream);
	fclose(tempStream);
	fclose(outputStream);
	remove("temp.tmp");
	printf("Results saved to \"%s\".\n", outputFileName);
	return 0;
}

int screenToScreen(void){
	FILE *tempStream;
	char str[999];

	tempStream = fopen("temp.tmp", "w");
	fflush(stdin);
	printf("Enter text below, to exit type \"save\" on new line\n");
	printf("------------------------------------------------------\n");
	while(1){
		gets(str);
		if(!strcmp(str, "save")){
			fclose(tempStream);
			tempStream = fopen("temp.tmp", "r");
			break;
		}
		fprintf(tempStream, "%s\n", str);
	}

	symbolsInComments(tempStream, stdout);
	rewind(tempStream);
	symbolsInIdentificators(tempStream, stdout);
	fclose(tempStream);

	return 0;
}

void symbolsInComments(FILE* inputStream, FILE* outputStream){
	int symbolsCount = 0, c, state = 1;
	
	while((c = fgetc(inputStream)) != EOF){
			switch(state){
				case 1: switch(c){
						case '/': state=2;break;
						}
						break;

				case 2: switch(c){
							case '/': state=3; break;
							case '*': state=4; break;
							default: state =1;
						}
						break;

				case 3: switch(c){
							case '\n': state=1; break;
							default: if(c!=' ' && c!='\t' && c!='\n') symbolsCount++;
						}
						break;

				case 4: switch(c){
							case '*': state=5; break;
							default: if(c!=' ' && c!='\t' && c!='\n') symbolsCount++;
						}
						break;

				case 5: switch (c){
							case '/': state=1; break;
							case '*': if(c!=' ' && c!='\t' && c!='\n') symbolsCount++; break;
							default: state=4; if(c!=' ' && c!='\t' && c!='\n') symbolsCount++;
						}
			}
		}

	fprintf(outputStream, "Total meaningful symbols in comments: %d\n", symbolsCount);
}

void symbolsInIdentificators(FILE* inputStream, FILE* outputStream){
	unsigned i;
	int flag, flag1, flag2, symbols = 0;
	char str[1000];

	while((fgets(str, sizeof str, inputStream)) != NULL){
		flag=0;
		flag1=0;
		flag2=0;
		
		for(i=0;i<strlen(str);i++){

			if(str[i]=='\"' && !flag) flag=1; // ne tyrsim v kavi4kite;
			else if(str[i]=='\"' && str[i-1]!='\\' && flag==1) flag=0;

			if(!flag && str[i]=='/' && str[i+1]=='/') break; // pri nalicieto na Cpp krai na tyrseneto v tozi red;

			if(!flag && str[i]=='/' && str[i+1]=='*') flag=2;// ne tyrsim v C komentarite;
			else if(flag==2 && str[i]=='*' && str[i+1]=='/') flag=0;
			
			if(!flag){
				if(str[i-5]=='v' && str[i-4]=='o' && str[i-3]=='i' && str[i-2]=='d') flag1=1;
				else if(str[i-5]=='c' && str[i-4]=='h' && str[i-3]=='a' && str[i-2]=='r' && str[i-1]==' ') flag1=1;
				else if(str[i-4]=='i' && str[i-3]=='n' && str[i-2]=='t' && str[i-1]==' ') flag1=1;
				else if(str[i-6]=='f' && str[i-5]=='l' && str[i-4]=='o' && str[i-3]=='a' && str[i-2]=='t' && str[i-1]==' ') flag1=1;
				else if(str[i-7]=='d' && str[i-6]=='o' && str[i-5]=='u' && str[i-4]=='b' && str[i-3]=='l' && str[i-2]=='e' && str[i-1]==' ') flag1=1;

				if(flag1 && !isspace(str[i])){
					if(str[i]==';') flag1=0;
					else if(str[i]=='=' && !flag2) flag2=1;
					else if(str[i]==',' && flag2) flag2=0;
					else if(str[i]=='(' && !flag2) flag2=2;
					else if(str[i]==')' && flag2) flag2=0;
					else if(!flag2 && (isalnum(str[i]) || str[i]=='_' || str[i]=='-')) symbols++;
				}
			}
		}
	}
	
	fprintf(outputStream, "Symbols in identificators: %d\n", symbols);
}