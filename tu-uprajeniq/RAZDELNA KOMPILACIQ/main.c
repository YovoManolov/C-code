#include <stdlib.h>
#include "arraymanip.h"
int main ()
{
    int arr[20],size = 5,ch;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    while(1)
    {
        system ("CLS");
        switch (mainMenu())
        {
            case 1:
                size = removeElement (arr, size);
				break;
            case 2:
                size = addElementEnd (arr, size);
				break;
            case 3:
                size = addElementAtPositoin (arr, size);
				break;
            case 4:
                printArray(arr,size);
				break;
            case 0: return 0;

        }
         system("pause");
    }
    return 0;
}

