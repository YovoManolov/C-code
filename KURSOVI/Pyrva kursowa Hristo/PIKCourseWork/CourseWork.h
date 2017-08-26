#ifndef COURSE_WORK_H_
#define COURSE_WORK_H_


int menu(void);
int fileToFile(void);
int fileToScreen(void);
int screenToFile(void);
int screenToScreen(void);
void linesInText(FILE* inputStream, FILE* outputStream);
void numberOfcommentsInText(FILE* inputStream, FILE* outputStream);
void insertingCommentsInText(FILE* inputStream, FILE* outputStream);
void getFileName(char* fileName, int mode);

#endif /// ARRAYMANIP_H_
