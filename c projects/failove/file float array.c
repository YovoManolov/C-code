/*��������� �� ����� �� 10 ��������
� ����� � ������� ������� ��� ����, ���� ����� �� ����� �������
����� ������� �� ������ �� ������� ��������� , ��� ���� ������� �� �������.
(�������� �� � ������� �������� ������� ������ , ������������ ����� ������ ������ ������� �� 
������� ������-������� ��������.*/

#include <stdio.h>
#include <stdlib.h>

double [10]= {10.23,19.87,1002.23,12.9,0.897,
11.45,75.34,0.0,875.875};
int main (void) {
	int i;
	FILE *fp;
	
	if((fp=fopen ("myfile","wb"))==NULL) {
		printf("Cannot open file .\n");
		exit (1);
	}
	
	/*���������� �� ������*/
	 for ( i=0;i<10;i++) {
	 	if(fread(&d[i],sizeof(double),1,fp) !=1){
	 		printf("read error.\n");
	 		exit(1);
		 }
		 fclose (fp);
		 /*izwejdane na masiva*/
		  for(i=0 ;i <10;i++)printf( "%f",d[i]);
		  return 0;
	 }
	return 0;
}
