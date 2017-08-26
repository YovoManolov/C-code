#include <stdio.h>
#include <stdlib.h>
#include "arraymanip.h"

int removeElement (int *arr, int size)
{
    int index, i;
    printf ("Enter element to remove: ");
    scanf ("%d",&index);

    for (i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}
int addElementEnd (int *arr, int size)
{
    int element;
    printf ("Enter new element ");
    scanf ("%d",&element);

    arr[size + 1] = element;

    return size + 1;
}
int addElementAtPositoin (int *arr, int size)
{
    int element, position,i;
    printf ("Enter element: ");
    scanf ("%d", &element);
    printf ("Enter position: ");
    scanf ("%d", &position);

    for (i = size - 1; i >= position; i--)
    {
        arr[i + i] = arr[i];
    }
    arr[position] = element;

    return size + 1;
}
void printArray (int *arr,int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf ("Element %d = %d\n", i, arr[i]);
    }
}
int mainMenu (void)
{
    int ch;

    printf ("1. Remove Element \n");
    printf ("2. Add Element End\n");
    printf ("3. Add Element At Positoin\n");
    printf ("4. Print Array \n");
    printf ("5. Exit \n");

    printf ("Select option: ");
    scanf ("%d",&ch);
    return ch;
}
