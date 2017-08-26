#include <stdio.h>
#include <stdlib.h>
int arr[26];
int main(){
int n, i;
char c;
FILE *fp;
fp=fopen("test", "r");
if(fp==NULL){printf("error");exit(0);}
while(1)
{
fscanf(fp, "%c", &c);
if(c=='.' || c== '!' || c=='?')break;
if(c>='A' && c<='Z')arr[c-'A']++;
if(c>='a' && c<='z')arr[c-'a']++;
}
fclose(fp);
for(i=0;i<26;i++){
if(arr[i])
printf("%c - %d \n", (i+'a'), arr[i]);
}
return 0;
}
