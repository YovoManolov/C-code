#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Person
{
	char name[32];
	char number[32];
} person;

int menu(){
	int i;
	
	printf(" __/MAIN MENU\\_______________________\n");
	printf("|                                    |\n");
	printf("|   1. LOAD FILE                     |\n");
	printf("|   2. SAVE FILE                     |\n");
	printf("|   3. PRINT PHONEBOOK               |\n");
	printf("|   4. ENTER NAME                    |\n");
	printf("|   5. SEARCH                        |\n");
	printf("|   6.                               |\n");
	printf("|   0. EXIT                          |\n");
	printf("|____________________________________|\n");
	do{
		printf("SELECT OPTION: ");
		fflush(stdin);
		scanf("%i", &i);
	}while(i < 0 || i> 6);

	return i;
}

void enterName(person* data, unsigned *lastEl)
{
	if(*lastEl < 50){
		fflush(stdin);
		printf("Enter name: ");
		gets(data[*lastEl].name);
		printf("Enter phone number: ");
		gets(data[*lastEl].number);
		(*lastEl)++;
	}
	else
	{
		printf("Book is full");
	}
}

void printPerson(person data)
{
	printf("NAme: %s ", data.name);
	printf("NUmber: %s\n", data.number);
}

void search (person *data, unsigned lastEl)
{
	int i,flag=0;
	char searchName[20];
	printf ("Enter name search: ");
	fflush(stdin);
	gets(searchName);
	for (i=0; i < lastEl; i++)
	{
		if (!(strcmp(searchName,data[i].name)))	
		{
			printPerson (data[i]);
			flag = 1;
		}
	}
	if (!flag) printf ("NOT FOUND");
}

void saveFile(unsigned lastEl, person* data)
{
	FILE* fp;
	char fileName[32];

	if(lastEl > 0){
		printf("Enter fileName: ");
		fflush(stdin);
		gets(fileName);
		if(!(fp = fopen(fileName, "wb")))
		{
			printf("ERROR!");
			return;	
		}
		fwrite(data, sizeof(person), lastEl, fp);
		fclose(fp);
		return;
	}
	printf("PhoneBook is empty!\n");
}


/*	case 1: loadFile(&lastEl, data);
	break;*/
void loadFile(unsigned *lastEl, person* data)
{
	FILE* fp;
	char fileName[32];
	*lastEl = 0;

	printf("Enter fileName: ");
	fflush(stdin);
	gets(fileName);
	if(!(fp = fopen(fileName, "rb")))
	{
		printf("FNF!");
		return;
	}
	while(fread(&data[*lastEl], sizeof(person), 1, fp))
	{
		(*lastEl)++;
	}
	
	fclose(fp);
	printf("FILE LOADED");
}

void printAll(person* data, unsigned lastEl)
{
	int i;
	if(lastEl < 1)
	{
		printf("Empty!\n");
		return;
	}

	for(i = 0; i < lastEl; i++)
	{
		printPerson(data[i]);
	}
}

int main(void){
	unsigned lastEl = 0;
	char fileName[32];
	person data[50];

	while(1){
		system("cls");
		switch(menu()){
			case 1: loadFile(&lastEl, data);
				break;
			case 2: saveFile(lastEl, data);
				break;
			case 3: printAll(data, lastEl);
				break;
			case 4: enterName(data, &lastEl);
				printf("%u", lastEl);
				break;
			case 5: search (data, lastEl);
				break;
			case 6:// screenToScreen();
				break;
			default: 
				exit(0);
		}
		system("pause");
	}
}
