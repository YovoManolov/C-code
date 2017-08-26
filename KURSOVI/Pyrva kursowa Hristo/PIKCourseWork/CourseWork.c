#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CourseWork.h"

int menu()
{
	int i;

	printf(" __/MAIN MENU\\_______________________\n");
	printf("|                                    |\n");
	printf("|   1. FILE TO FILE                  |\n");
	printf("|   2. FILE TO SCREEN                |\n");
	printf("|   3. KBRD TO FILE                  |\n");
	printf("|   4. KBRD TO SCREEN                |\n");
	printf("|   0. EXIT                          |\n");
	printf("|____________________________________|\n");

    printf("SELECT OPTION: ");
    fflush(stdin);
    scanf("%i", &i);

    if(i > 4 || i < 0)
    {
        printf("Please select a valid command\n");
        return 5;
    }
	return i;
}


int fileToFile(void)
{
	char inputFileName[256], outputFileName[256];
	int numberOfLines;
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
    insertingCommentsInText(inputStream,outputStream);
    rewind(inputStream);
	linesInText(inputStream, outputStream);
	rewind(inputStream);
	numberOfcommentsInText(inputStream, outputStream);
	fclose(inputStream);
	fclose(outputStream);

	printf("Results saved to \"%s\".\n", outputFileName);
	return 0;
}

int fileToScreen(void)
{
	char inputFileName[256];
	FILE* inputStream;

	getFileName(inputFileName, 1);
	if(!(inputStream = fopen(inputFileName, "r"))){
		fprintf(stderr, "Error opening file!\n");
		return -1;
	}

	insertingCommentsInText(inputStream,stdout);
	rewind(inputStream);
	linesInText(inputStream, stdout);
	rewind(inputStream);
	numberOfcommentsInText(inputStream, stdout);
    rewind(inputStream);
	fclose(inputStream);

	return 0;
}


int screenToFile(void)
{
	char outputFileName[256];
	FILE *outputStream, *tempStream;
	char str[999];

	tempStream = fopen("temp.tmp", "w");
	fflush(stdin);
	printf("Enter text below, to exit type \"save\" on new line\n");
	printf("------------------------------------------------------\n");
	while(1){
		gets(str);
		if(!strcmp(str, "save"))
        {
			fclose(tempStream);
			system("pause");
			tempStream = fopen("temp.tmp", "r");
			break;
		}
		fprintf(tempStream, "%s\n", str);
	}


	printf("Please enter the name of the file in which you want to save\n");
	gets(&outputFileName);
	if(!(outputStream = fopen(outputFileName, "w")))
    {
		fprintf(stderr, "Error opening file!\a\n");
		return -1;
	}

    insertingCommentsInText(tempStream,outputStream);
    rewind(tempStream);
	linesInText(tempStream, outputStream);
	rewind(tempStream);
	numberOfcommentsInText(tempStream, outputStream);
	fclose(tempStream);
	fclose(outputStream);
	remove("temp.tmp");
	printf("Results saved to \"%s\".\n", outputFileName);
	return 0;
}

int screenToScreen(void)
{
	FILE *tempStream;
	char str[999];

	tempStream = fopen("temp.tmp", "w");
	fflush(stdin);
	printf("Enter text below, to exit type \"save\" on new line\n");
	printf("------------------------------------------------------\n");
	while(1)
    {
		gets(str);
		if(!strcmp(str, "save"))
        {
			fclose(tempStream);
			tempStream = fopen("temp.tmp", "r");
			break;
		}
		fprintf(tempStream, "%s\n", str);
	}

    insertingCommentsInText(tempStream,stdout);
    rewind(tempStream);
	linesInText(tempStream, stdout);
	rewind(tempStream);
	numberOfcommentsInText(tempStream, stdout);
	fclose(tempStream);

	return 0;
}

void linesInText(FILE* inputStream, FILE* outputStream)
{
	int linesCount = 1;
	char c;

	while((c = fgetc(inputStream)) != EOF)
        {
            if(c == '\n')
            {
                linesCount++;
            }
        }

	fprintf(outputStream, "Total lines in the text: %d\n", linesCount);
}

void numberOfcommentsInText(FILE* inputStream, FILE* outputStream)
{
	char c;
	int commentsCount = 0, flag = 0, mode = 0;

	while((c = fgetc(inputStream)) != EOF)
        {
            if(mode == 1 && c != '\n')
            {
                continue;
            }

            if(c == '\\' && flag == 1)
            {
                commentsCount++;
                flag = 0;
                mode = 1;
            }

            if(c == '\\' && flag == 0)
            {
                flag = 1;
            }

            if(mode == 1 && c == '\n')
            {
                mode = 0;
            }
		}

	fprintf(outputStream, "Total comments in the text: %d\n", commentsCount);
}

void insertingCommentsInText(FILE* inputStream, FILE* outputStream)
{
	char comment[200], line[999], str[200], c;
	char* boolPointer;
	int i = 0, flag = 0, k;

	printf("Enter str:");
	gets(str);
	printf("Enter comment:");
	gets(comment);

	while((c = fgetc(inputStream)) != EOF)
    {
        fprintf(outputStream, "%c", c);
        line[i] = c;
        boolPointer = strstr(line, str); 
        if(boolPointer != NULL && flag == 0)
        {
            fprintf(outputStream, "/*%s*/", comment);
            for(k = 0; k < strlen(line); k++)
            {
                line[k] = '0';
            }
        }
        i++;
    }
}

void getFileName(char* fileName, int mode)
{
	while(1)
    {
		fflush(stdin);
		if(mode == 1){
			printf("Input file name(.TXT): ");
			gets(fileName);
			if(toupper(fileName[strlen(fileName) - 1]) == 'T' && toupper(fileName[strlen(fileName) - 2]) == 'X' && toupper(fileName[strlen(fileName) - 3]) == 'T' &&
            (fileName[strlen(fileName) - 4] == '.'))
            {
                return;
			}

		}
		else
        {
			printf("Output File Name (.TXT): ");
			gets(fileName);
			if(toupper(fileName[strlen(fileName) - 1]) == 'T' && toupper(fileName[strlen(fileName) - 2]) == 'X' && toupper(fileName[strlen(fileName) - 3]) == 'T' &&
            (fileName[strlen(fileName) - 4] == '.'))
            {
                return;
			}
			return;
		}
	}
}
