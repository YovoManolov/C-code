#include <stdio.h> 

int main (void) {
    in a [10] = {10,20,30,40,50,60,70,80,90,100} ;
    int *p ;
    p = a ; /*�� p �� ��������� ������ �� �������� ��  a*/
    
    
    /*���� �� ���������� ������ ������� � ������� ������� �� � */
    printf("%d %d %d\n" , *p,  *(p+1), *(p+2));
    
    //towa izwurshva syshtoto no izpolzwa a 
    printf("%d %d %d", a[0], a[1], a[2]); 
	
	return 0;
}
