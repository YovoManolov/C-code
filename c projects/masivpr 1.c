#include <stdio.h>
int main(){
int sqrt[10];
int i;

for (i=1;i<11;i++) sqrt[i-1] = i*i;
for (i=0; i<10;i++) printf("%d",sqrt [i]);

return 0;
}
