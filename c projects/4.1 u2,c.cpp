#include <stdio.h>
int main(void)
{short int i;//short int със знак
unsigned short int u;//short int без знак

u = 33000;
i = u;
printf("%hd %hu",i,u);
return 0;
}
