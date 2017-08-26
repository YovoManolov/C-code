-#include <stdio.h> 

int main () {
	int flag = 0x00;
	//bit 1 -> kavichka
	//bit 2 -> krai
	//bit 3 -> skobichka
	//bit 4 -> krai
	//0000 0000 0000 0000 0000 0000 0000 1111 = 0xF
	
	int i=0 ;   char  arr[20] = {"[\" Ivan \"]"};
	
	 while (i!= 20) {
	 	if(arr[i]== '[' && !flag   ) {flag|= 0x04;}  
		 if(arr[i]== '"' && flag&0x04) {flag|= 0x01;}
		 if(arr[i]== '"' && flag&0x01
		                 && flag&0x04) {flag|= 0x02;}
		 if(arr[i]== ']' && flag&0x01
		                 && flag&0x02 
						 && flag&0x04) {flag|= 0x08;}
	 	i++;
	 }
	 if(flag == 0xF) printf("%s\n" , "stringa e veren" );
	 else printf("%s\n","greshnooooooo!!!"); 
	 return 0;
}

