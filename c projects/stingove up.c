#include <string.h>
#include <stdio.h>

int main (void)
{
	char str1[80],str2[80];
	int i;
	
	
	printf("Enter the first string: ");
	gets(str1);
	printf("Enter the second string: ");
	gets(str2);
	
	/*proverka duljinata na nizovete */
	printf("%s is %d char long\n" ,str1,strlen(str1));
	printf("%s is %d char long\n", str2,strlen(str2));



    /*sravnqvane na nizovete*/
	i = strcmp(str1,str2);
	if(!i) printf("the string are equal.\n");
	else if (i<0) printf("%s is less than %s\n",str1, str2);
	
	else printf("%s is greater than %s\n",str1,str2);
	/*konkatinirane na str2 kum kraq na str 1 ako ima dostatuchno mqsto*/
	if(strlen(str1)+strlen(str2)<80) {
	 strcat(str1,str2);
	 printf(%s\n,str1);
	}
	/*копиране на  стр2 в стр1 */
	strcpy(str1,str2);
	printf("%s %s\n",str1,str2);
	
	return 0;
	
}
