#include<stdio.h>
void prtBk();
 
int main () {
	printf("please input a line: ");
	prtBk(); // вика се prtBk()
	return 0;
}
void prtBk() {
	int c;//Прочита следващия символ
	if((c=getchar())!= EOF /*end of file*/ ){
		/*устанпвява ,че въведеният символ
		 не е нито точка ,нито символ за нов ред*/
	    if(   !( (c=='.')||(c=='\n') )   ){
		 	
	    	prtBk();/*прави рекурсивно извикване
					, както в стека(First in - Last out) 
					се заделя необходимата за това памет .*/'
			
			}
			
	    	printf("%c",c);
	}
	else{
	   printf("Error");
	}
}
	

