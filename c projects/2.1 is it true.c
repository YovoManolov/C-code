# include <stdio.h>

int main(void)

{
    int answer;
    printf("what is 10+14? ");
    scanf("%d", &answer);
    if (answer == 10+14) printf ("Right!");
    else printf ("False!");

    return 0;
}

