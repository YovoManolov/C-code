#include<stdio.h>
#include<string.h>

typedef struct Person
{
    unsigned age;
    char number[16];
    char name[32];
}person;

void PrintPhoneBook(person p[],unsigned lastIndex)
{
    int index = 0;

    for(;index < lastIndex; index++)
    {
        printf("Name: %s\n", p[index].name);
        printf("Age: %u\n", p[index].age);
        printf("Number: %s\n", p[index].number);
    }

}

void addPerson(person* p,)
{
    printf("Enter Age: ");
    scanf("%d", &p->age);
    fflush(stdin);
    printf("Enter Name: ");
    gets(p->name);
    printf("Enter Number: ");
    gets(p->number);
}


int main(void)
{
    person phonebook[50];
    unsigned lastIndex = 0;
    addPerson(&phonebook[lastIndex]);
    lastIndex++;
    addPerson(&phonebook[lastIndex]);
    lastIndex++;

    PrintPhoneBook(phonebook, lastIndex);

    return 0;
}
