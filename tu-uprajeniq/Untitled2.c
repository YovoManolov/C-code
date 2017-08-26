#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef unsigned char uc;

 typedef struct Person
 {
    unsigned age;
    char name[20];
    struct Person* next;
 }person;

void PrintPersonInfo(person* p){
    printf("AGE: %u\n", p->age);
    printf("NAME: %s\n",p->name);
}

int main()
{
    person p;

    p.age = 17;
    strcpy(p.name, "halibrqm");
    PrintPersonInfo(&p);
}
