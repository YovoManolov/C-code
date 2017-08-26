#include <stdio.h>
 
void towers(int, char, char, char);
 
int main()
{
    int num;
 
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'S', 'D', 'A');
    return 0;
}
void towers(int num, char sourcepeg, char destpeg, char auxpeg)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", sourcepeg, destpeg);
        return;
    }
    towers(num - 1, sourcepeg, auxpeg, destpeg);
    printf("\n Move disk %d from peg %c to peg %c", num, sourcepeg, destpeg);
    towers(num - 1, auxpeg, destpeg, sourcepeg);
}
