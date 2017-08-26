# include<stdio.h>
#include<string.h>
int main(){
	int a;
	char stri[] = " i ";
	
	char str1_9_1[] = "edno",   str1_9_2[] = "dve",  str1_9_3[] = "tri",  str1_9_4[] = "chetiri",  str1_9_5[] = "pet";
	char str1_9_6[] = "shest",  str1_9_7[] = "sedem",  str1_9_8[] = "osem",  str1_9_9[] = "devet";
	
	char str11_19_1[] = "edinadeset",  str11_19_2[] = "dvanadeset\n",  str11_19_3[] = "trinadeset\n",  str11_19_4[] = "chetirinadeset\n";
	char str11_19_5[] = "pentnadeset\n",  str11_19_6[] = "shestnadeset\n",  str11_19_7[] = "sedemnadeset\n",  str11_19_8[] = "osemnadeset\n";
	char str11_19_9[] = "devetnadeset\n";
	
	char str20_29[]="dvadeset" , str30_39[]="trideset", str40_49[]="chetirideset", str50_59[]="petdeset";
	char str60_69[]="shestdeset", str70_79[]="sedemdeset", str80_89[]="osemdeset", str90_99[]="devetdeset";
	
	
	
	
	
	printf("Enter number from 0 to 999");
	scanf("%d",&a);
	if(0 <= a <= 10){
		if(a == 0){
			printf("nula");
		}
		if(1 <= a <= 9){
			switch (a) {
				case 1 :
					printf("%c\n",str1_9_1);
					break;
				case 2 :
					printf("%c\n",str1_9_2);
					break;
				case 3 :
					printf("%c\n",str1_9_3);
					break;
				case 4 :
					printf("%c\n",str1_9_4);
					break;
				case 5 :
					printf("%c\n",str1_9_5);
					break;
				case 6 :
					printf("%c\n",str1_9_6);
					break;
				case 7 :
					printf("%c\n",str1_9_7);
					break;
				case 8 :
					printf("%c\n",str1_9_8);
					break;
				case 9 :
					printf("%c\n",str1_9_9);
					
			    default :printf("chisloto ne e mejdu 1 i 9 \n");
			    
			    break;
             	
				}
			}
		
		if( a == 10 ){
			printf("deset\n");
		}
	}
        if(11 <= a <= 19){
    		switch (a) {
				case 1 :
					printf("%c\n",str11_19_1);
					break;
				case 2 :
					printf("%c\n",str11_19_2);
					break;
				case 3 :
					printf("%c\n",str11_19_3);
					break;
				case 4 :
					printf("%c\n",str11_19_4);
					break;
				case 5 :
					printf("%c\n",str11_19_5);
					break;
				case 6 :
					printf("%c\n",str11_19_6);
					break;
				case 7 :
					printf("%c\n",str11_19_7);
					break;
				case 8 :
					printf("%c\n",str11_19_8);
					break;
				case 9 :
					printf("%c\n",str11_19_9);
					
			    default :printf("chisloto ne e mejdu 11 i 19 \n");
			    
			    break;
             	
				}
			}
    	
	else if(19<a<=99){
		       if (19<a<=29){
		       	  if(a == 20) {
					  printf("%c\n",str20_29);
					  }
				  else if(21<=a<=29){
				  switch (a) {
				case 1 :
						strcat(str20_29, stri);
	                    strcat(str20_29, str1_9_1);
                        printf("%s",str20_29);
					break;
				case 2 :
					strcat(str20_29, stri);
	                    strcat(str20_29, str1_9_2);
                        printf("%s",str20_29);
					break;
				case 3 :
				    strcat(str20_29, stri);
	                    strcat(str20_29, str1_9_3);
                        printf("%s",str20_29);
					break;
				case 4 :
					strcat(str20_29, stri);
	                    strcat(str20_29, str1_9_4);
                        printf("%s",str20_29);
					break;
				case 5 :
					strcat(str20_29, stri);
	                    strcat(str20_29, str1_9_5);
                        printf("%s",str20_29);
					break;
				case 6 :
					strcat(str20_29, stri);
	                    strcat(str20_29, str1_9_6);
                        printf("%s",str20_29);
					break;
				case 7 :
					strcat(str20_29, stri);
	                    strcat(str20_29, str1_9_7);
                        printf("%s",str20_29);
					break;
				case 8 :
					strcat(str20_29, stri);
	                    strcat(str20_29, str1_9_8);
                        printf("%s",str20_29);
					break;
				case 9 :
					strcat(str20_29, stri);
	                    strcat(str20_29, str1_9_9);
                        printf("%s",str20_29);
                    break;
					
			    default :printf("chisloto ne e mejdu 21 i 29 \n");
			    
			    break;
             	
			         	}
				   }
				   
	else if (30<a<=39){
					  if(a == 30) {
					  printf("%c\n",str30_39);
					  }
					  else if(21<=a<=29){
				  switch (a) {
				case 1 :
						strcat(str30_39, stri);
	                    strcat(str30_39, str1_9_1);
                        printf("%s",str30_39);
					break;
				case 2 :
					strcat(str30_39, stri);
	                    strcat(str30_39, str1_9_2);
                        printf("%s",str20_29);
					break;
				case 3 :
				    strcat(str30_39, stri);
	                    strcat(str30_39, str1_9_3);
                        printf("%s",str30_39);
					break;
				case 4 :
					strcat(str30_39, stri);
	                    strcat(str30_39, str1_9_4);
                        printf("%s",str30_39);
					break;
				case 5 :
					strcat(str30_39, stri);
	                    strcat(str30_39, str1_9_5);
                        printf("%s",str30_39);
					break;
				case 6 :
					strcat(str30_39, stri);
	                    strcat(str30_39, str1_9_6);
                        printf("%s",str30_39);
					break;
				case 7 :
					strcat(str30_39, stri);
	                    strcat(str30_39, str1_9_7);
                        printf("%s",str30_39);
					break;
				case 8 :
					strcat(str30_39, stri);
	                    strcat(str30_39, str1_9_8);
                        printf("%s",str30_39);
					break;
				case 9 :
				    strcat(str30_39, stri);
	                    strcat(str30_39, str1_9_9);
                        printf("%s",str30_39);
                    break;
					
			    default :printf("chisloto ne e mejdu 31 i 39 \n");
			    
			    break;
             	
			         	}
				   }
			   }
		else if (40<a<=49){
				   	if(a == 40) {
					  printf("%c\n",str40_49);
					  }
					  else if(41<=a<=49){
				  switch (a) {
				case 1 :
						strcat(str40_49, stri);
	                    strcat(str40_49, str1_9_1);
                        printf("%s",str40_49);
					break;
				case 2 :
					strcat(str40_49, stri);
	                    strcat(str40_49, str1_9_2);
                        printf("%s",str40_49);
					break;
				case 3 :
				   strcat(str40_49, stri);
	                    strcat(str40_49, str1_9_3);
                        printf("%s",str40_49);
					break;
				case 4 :
					strcat(str40_49, stri);
	                    strcat(str40_49, str1_9_4);
                        printf("%s",str40_49);
					break;
				case 5 :
					strcat(str40_49, stri);
	                    strcat(str40_49, str1_9_5);
                        printf("%s",str40_49);
					break;
				case 6 :
					strcat(str40_49, stri);
	                    strcat(str40_49, str1_9_6);
                        printf("%s",str40_49);
					break;
				case 7 :
					strcat(str40_49, stri);
	                    strcat(str40_49, str1_9_7);
                        printf("%s",str40_49);
					break;
				case 8 :
					strcat(str40_49, stri);
	                    strcat(str40_49, str1_9_8);
                        printf("%s",str40_49);
					break;
				case 9 :
				    strcat(str40_49, stri);
	                    strcat(str40_49, str1_9_9);
                        printf("%s",str40_49);
                    break;
					
			    default :printf("chisloto ne e mejdu 41 i 49 \n");
			    
			    break;
             	
			         	}
				   }
			   }
		else if (50<a<=59){
				   	if(a == 50) {
					  printf("%c\n",str50_59);
					  }
					  else if(51<=a<=59){
				  switch (a) {
				case 1 :
						strcat(str50_59, stri);
	                    strcat(str50_59, str1_9_1);
                        printf("%s",str50_59);
					break;
				case 2 :
					strcat(str50_59, stri);
	                    strcat(str50_59, str1_9_2);
                        printf("%s",str50_59);
					break;
				case 3 :
				   strcat(str50_59, stri);
	                    strcat(str50_59, str1_9_3);
                        printf("%s",str50_59);
					break;
				case 4 :
					strcat(str50_59, stri);
	                    strcat(str50_59, str1_9_4);
                        printf("%s",str50_59);
					break;
				case 5 :
					strcat(str50_59, stri);
	                    strcat(str50_59, str1_9_5);
                        printf("%s",str50_59);
					break;
				case 6 :
					strcat(str50_59, stri);
	                    strcat(str50_59, str1_9_6);
                        printf("%s",str50_59);
					break;
				case 7 :
					strcat(str50_59, stri);
	                    strcat(str50_59, str1_9_7);
                        printf("%s",str50_59);
					break;
				case 8 :
					strcat(str50_59, stri);
	                    strcat(str50_59, str1_9_8);
                        printf("%s",str50_59);
					break;
				case 9 :
				    strcat(str50_59, stri);
	                    strcat(str50_59, str1_9_9);
                        printf("%s",str50_59);
                    break;
					
			    default :printf("chisloto ne e mejdu 51 i 59 \n");
			    
			    break;
             	
			         	}
				   }
			   }	   	   
		else if (60<a<=69){
				   	if(a == 60) {
					  printf("%c\n",str60_69);
					  }
					  else if(61<=a<=69){
				  switch (a) {
				case 1 :
						strcat(str60_69, stri);
	                    strcat(str60_69, str1_9_1);
                        printf("%s",str60_69);
					break;
				case 2 :
					strcat(str60_69, stri);
	                    strcat(str60_69, str1_9_2);
                        printf("%s",str60_69);
					break;
				case 3 :
				  sstrcat(str60_69, stri);
	                    strcat(str60_69, str1_9_3);
                        printf("%s",str60_69);
					break;
				case 4 :
					strcat(str60_69, stri);
	                    strcat(str60_69, str1_9_4);
                        printf("%s",str60_69);
					break;
				case 5 :
					strcat(str60_69, stri);
	                    strcat(str60_69, str1_9_5);
                        printf("%s",str60_69);
					break;
				case 6 :
				strcat(str60_69, stri);
	                    strcat(str60_69, str1_9_6);
                        printf("%s",str60_69);
					break;
				case 7 :
				strcat(str60_69, stri);
	                    strcat(str60_69, str1_9_7);
                        printf("%s",str60_69);
					break;
				case 8 :
					strcat(str60_69, stri);
	                    strcat(str60_69, str1_9_8);
                        printf("%s",str60_69);
					break;
				case 9 :
				    strcat(str60_69, stri);
	                    strcat(str60_69, str1_9_9);
                        printf("%s",str60_69);
                    break;
					
			    default :printf("chisloto ne e mejdu 61 i 69 \n");
			    
			    break;
             	
			         	}
				   }
			   }
			   
		else if (70<a<=79){
				   	if(a == 70) {
					  printf("%c\n",str70_79);
					  }
					  else if(71<=a<=79){
				  switch (a) {
				case 1 :
						strcat(str70_79, stri);
	                    strcat(str70_79, str1_9_1);
                        printf("%s",str70_79);
					break;
				case 2 :
					strcat(str70_79, stri);
	                    strcat(str70_79, str1_9_2);
                        printf("%s",str70_79);
					break;
				case 3 :
				  strcat(str70_79, stri);
	                    strcat(str70_79, str1_9_3);
                        printf("%s",str70_79);
					break;
				case 4 :
					strcat(str70_79, stri);
	                    strcat(str70_79, str1_9_4);
                        printf("%s",str70_79);
					break;
				case 5 :
					strcat(str70_79, stri);
	                    strcat(str70_79, str1_9_5);
                        printf("%s",str70_79);
					break;
				case 6 :
				    strcat(str70_79, stri);
	                    strcat(str70_79, str1_9_6);
                        printf("%s",str70_79);
					break;
				case 7 :
				    strcat(str70_79, stri);
	                    strcat(str70_79, str1_9_7);
                        printf("%s",str70_79);
					break;
				case 8 :
					strcat(str70_79, stri);
	                    strcat(str70_79, str1_9_8);
                        printf("%s",str70_79);
					break;
				case 9 :
				    strcat(str70_79, stri);
	                    strcat(str70_79, str1_9_9);
                        printf("%s",str70_79);
                    break;
					
			    default :printf("chisloto ne e mejdu 71 i 79 \n");
			    
			    break;
             	
			         	}
				   }
			   }
		else if (80<a<=89)
				   	if(a == 80) {
					  printf("%c\n",str80_89);
					  }
					  else if(81<=a<=89){
				  switch (a) {
				case 1 :
						strcat(str80_89, stri);
	                    strcat(str80_89, str1_9_1);
                        printf("%s",str80_89);
					break;
				case 2 :
					strcat(str80_89, stri);
	                    strcat(str80_89, str1_9_2);
                        printf("%s",str80_89);
					break;
				case 3 :
				  	strcat(str80_89, stri);
	                    strcat(str80_89, str1_9_3);
                        printf("%s",str80_89);
					break;
				case 4 :
						strcat(str80_89, stri);
	                    strcat(str80_89, str1_9_4);
                        printf("%s",str80_89);
					break;
				case 5 :
						strcat(str80_89, stri);
	                    strcat(str80_89, str1_9_5);
                        printf("%s",str80_89);
					break;
				case 6 :
					strcat(str80_89, stri);
	                    strcat(str80_89, str1_9_6);
                        printf("%s",str80_89);
					break;
				case 7 :
					strcat(str80_89, stri);
	                    strcat(str80_89, str1_9_7);
                        printf("%s",str80_89);
					break;
				case 8 :
						strcat(str80_89, stri);
	                    strcat(str80_89, str1_9_8);
                        printf("%s",str80_89);
					break;
				case 9 :
				    	strcat(str80_89, stri);
	                    strcat(str80_89, str1_9_9);
                        printf("%s",str80_89);
                    break;
					
			    default :printf("chisloto ne e mejdu 81 i 89 \n");
			    
			    break;
             	
			         	}
				   }
			   }
		else if (90<a<=99){
		
				   	if(a == 90) {
					  printf("%c\n",str90_99);
					  }
					  else if(91<=a<=99){
				  switch (a) {
				case 1 :
						strcat(str90_99, stri);
	                    strcat(str90_99, str1_9_1);
                        printf("%s",str90_99);
					break;
				case 2 :
					strcat(str90_99, stri);
	                    strcat(str90_99, str1_9_2);
                        printf("%s",str90_99);
					break;
				case 3 :
				  	strcat(str90_99, stri);
	                    strcat(str90_99, str1_9_3);
                        printf("%s",str90_99);
					break;
				case 4 :
						strcat(str90_99, stri);
	                    strcat(str90_99, str1_9_4);
                        printf("%s",str90_99);
					break;
				case 5 :
						strcat(str90_99, stri);
	                    strcat(str90_99, str1_9_5);
                        printf("%s",str90_99);
					break;
				case 6 :
					strcat(str90_99, stri);
	                    strcat(str90_99, str1_9_6);
                        printf("%s",str90_99);
					break;
				case 7 :
					strcat(str90_99, stri);
	                    strcat(str90_99, str1_9_7);
                        printf("%s",str90_99);
					break;
				case 8 :
					strcat(str90_99, stri);
	                    strcat(str90_99, str1_9_8);
                        printf("%s",str90_99);
					break;
				case 9 :
				    	strcat(str90_99, stri);
	                    strcat(str90_99, str1_9_9);
                        printf("%s",str90_99);
                    break;
					
			    default :printf("chisloto ne e mejdu 91 i 99 \n");
			    
			    break;
             	
			         	}
				   }
			   }	   	   	   	   	   	   	   	   	   
			   	   	   	   
	}

	return 0;
}
