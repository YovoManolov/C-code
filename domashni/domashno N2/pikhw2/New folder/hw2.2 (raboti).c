/*��������� ��������, ����� ���� ����������� �� ���� ����� � ��� ���� � �� ���������� � ��������� 
����������/������;��������� �� ������ ��-������ ���, � ��� �� ����� - � �����;
 �������� ��������� �� ����������� � �������; � ���������� �� ��������� �� ����������� ��������� 
 �� ������:
Both strings are longer or equal. // � ����� ���� �� ��-����� ��� ����� �� ���������� �� �������;
Both strings are shorter. // � ����� ���� �� ��-����;
Only one of the strings is longer or equal.// ���� ������ � ��-����� ��� �����;
���� ���� �������� ����� ����, � ��� ������������ �� � ������� �������� �� �����������;
*/

#include <stdio.h>
#include <string.h>
int main () {
	char str1[30],str2[20];
	int a, i, c;
	
	printf("Enter the fist string: ");
	gets(str1);
	printf("Enter the second string: ");
	gets(str2);	
	printf("Enter intiger: ");
	scanf("%d",& a);
	
    i = strcmp(str1,str2);
    if (!i) printf("%s %s\n",str1 ,str2);
    else if (i<0) printf("%s\n",str2);
    else if (i>0) printf("%s\n",str1);
    
   if( strlen(str1)>=a ||strlen(str2) >= a ) printf("Only one of the strings is longer or equal.");
   if ( strlen(str1)<a && strlen(str2)<a) printf("Both strings are shorter.");
   if( strlen(str1)>=a && strlen(str2) >= a ) printf("Both strings are longer or equal.");
   
   c = strcmp(str1,str2);
    if (!c) printf("the strings are equal. \n");
   
   return 0;
}
