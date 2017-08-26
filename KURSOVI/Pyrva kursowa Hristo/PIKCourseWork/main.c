#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CourseWork.h"

int main()
{
    while(1){
		system("cls");
		switch(menu())
		{
			case 1: fileToFile();
				break;
			case 2: fileToScreen();
				break;
			case 3: screenToFile();
				break;
			case 4: screenToScreen();
				break;
            case 5:
                continue;
			default:
				exit(0);
		}
		system("pause");
	}
}
