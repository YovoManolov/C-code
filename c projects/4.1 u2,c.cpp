#include <stdio.h>
int main(void)
{short int i;//short int ��� ����
unsigned short int u;//short int ��� ����

u = 33000;
i = u;
printf("%hd %hu",i,u);
return 0;
}
