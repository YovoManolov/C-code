#include<stdio.h>
void prtBk();
 
int main () {
	printf("please input a line: ");
	prtBk(); // ���� �� prtBk()
	return 0;
}
void prtBk() {
	int c;//������� ��������� ������
	if((c=getchar())!= EOF /*end of file*/ ){
		/*���������� ,�� ���������� ������
		 �� � ���� ����� ,���� ������ �� ��� ���*/
	    if(   !( (c=='.')||(c=='\n') )   ){
		 	
	    	prtBk();/*����� ���������� ���������
					, ����� � �����(First in - Last out) 
					�� ������ ������������ �� ���� ����� .*/'
			
			}
			
	    	printf("%c",c);
	}
	else{
	   printf("Error");
	}
}
	

