#include <stdio.h>

void rcopy(char *s1,char *s2);

int main (void) {
	char str[80];
	
	rcopy(str,"this is a test");
	printf(str);
	
	return 0;
}
//kopira s2 v s1 posredstvom rekursiq

void rcopy (char *s1,char *s2) {
	if(*s2)  {
		//ako ne e v kraq na s2
		rcopy(s1, s2);
	}
	else *s1 = '\0'; //null terminira niza
 }
