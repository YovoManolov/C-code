/*Програма , която организира работата на потребителя чрез меню, от което 
се избира едно от следните действия: (
§§  Чете от клавиатурата текст до въвеждане на звездичка и го съхранява в текстов файл
text.txt
§§  Прочита съдържанието на text.txt и извършва следните  статистически обработки: 
 ..........*Намира броя на думите(разделени с интервал или точка)
 ..........*Извежда думата с най много символи - (най-дългата дума)
 ..........*Извежда всички думи с четри символа
    Тези резултати програмата извежда на  екрана на монитора.
§§ Прочита съдържанието на text.txt и записва нов файл text1.txt , в който всички думи от 
text.txt се записват на нов ред.
§§ Прочита съдържанието на text1.txt и го извежда на екрана.
§§ Край на работата с програмата
) */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int counter0 = 0 /*case1*/ ,/* dyrji duljinata na str1_1*/ i = 0  ,counter1 /*case 2*/  = 0 , word_lenght [15000];
int num_of_stars[30000] ;
char str1_2 [30000],str1_3[30000];

void nov_red(FILE * fptxt,FILE * fptxt1);
void print_file(FILE * fptxt1);
void textTransition (FILE *fptxt); 
void wordCounter ( FILE * fptxt);
void wordLenghtHolder();
void longestWord ();
int menu();

int main() {
	FILE *fptxt ,*fptxt1 ;
	int word_lenght4 = 0; 
	int choice = 0; 
	
	int menu(){
	int i;
	
    printf("|__________________________________________________MENU___________________________________________________|\n\n");

 
     printf("|____1. Chete ot klaviaturata tekst do vyvejdane na zvezdichka i go syhranqva v  text.txt_________________|\n");
     printf("|____2. Prochita sydurjanieto na  text.txt i izvyrshva slednite statisticheski obrabotki__________________|\n"); 
	 printf("|________- Namira broq na dumite razdelieni s interval ili tochka_________________________________________|\n");
	 printf("|________- Izvejda dumata s naj- mnogo simvoli - (nai- dulgata duma)______________________________________|\n");
	 printf("|________- Izvejda vsichki dumi s chetiri simvola_________________________________________________________|\n");
	 printf("|________- Izvejda rezultatite na ekrana na monitora______________________________________________________|\n");
     printf("|____3. Prochita sudurjanieto na text.txt i zapisva nov fail text1.txt , w kojto vsichki dumi ot _________|\n");
     printf("|_______text.txt се se zapiswat na now red._______________________________________________________________|\n");
     printf("|____4. Prochita sydyrjanieto na text1.txt i go izvejda na ekrana.________________________________________|\n");
     printf("|____5. Exit______________________________________________________________________________________________|\n");
	//izprintira opciite

	do{
		printf("SELECT OPTION: ");
		//4istene na bufera
		fflush(stdin);
		scanf("%i", &i);
	}while(i < 0 || i> 5);
	 
	//vry6ta stoinosta
	return i;
}
		while(1){
		//4isti ekrana
		system("cls");
		//v zavisimost ot izbora na clienta - pra6ta v dadenata funkciq
	
    switch (menu()){
        case 1: 
		       textTransition(fptxt); 
        	break;
        case 2:  wordCounter(fptxt); // faund the number of words saparated by space or point.
                 wordLenghtHolder();
                 longestWord ();
			
           	if(word_lenght[i] == 4){ 
				word_lenght4 ++ ;
			}
			printf(" number of words with four letters is %d", word_lenght4 ) ;
        	break;
		case 3:/*Prochita sudurjanieto na text.txt i zapisva nov fail text1.txt , w kojto vsichki dumi ot 
     text.txt се se zapiswat na now red.*/
     
            nov_red(fptxt,fptxt1);
        	break;
		case 4:
	        print_file(fptxt1);
		    
        	break;		

        default:

            printf("Choice 5 selected");
            exit(0);
      }
     system("pause");
   }
	return 0;
}


void textTransition(FILE *fptxt){
	        char str1_1[30000];
	            if((fptxt = fopen("text.txt ","wb+")==NULL)) {
	     	printf("Cannot open file.\n");
	    	exit(1);
            }
            printf("Enter text from kaybord that contains a star :");
            for (i=0; i<30000 ;i++) 
				{
						    if(str1_1[i] != '*' /*__ascii cod for (*) ___ */ ){
							    int i = 0;
								
								while((str1_1[i] = getchar())!='\0'){
								        i++ ;
								getch();
						       }
						    }  
						i = counter0 ;
						
						     else if (str1_1[i] == '*' /*__ascii cod for (*) ___ */ ) {
						        break;
							 }			 
               }
   strncpy(str1_2,str1_1, counter0);
			           strncpy(str1_3,str1_1, counter0); //case 3
						fputs(str1_2,fptxt);
						fputs(str1_3,fptxt);
			           fclose (fptxt);				   	           
}


void wordCounter( FILE * fptxt)  {
	if((fptxt = fopen("text.txt ","rb+")==NULL)) {
	     	printf("Cannot open file.\n");
	    	exit(1);
            }
              for(i=0;i<counter0 /* Дължината на стринга до звездичката .*/;i++){
			      if(str1_2[i] == ' ' || str1_2[i] == '.'){
                 	++counter1;
			      }
			 }   
            printf("The number of words in the program is %d " , counter1 - 1);
}

void wordLenghtHolder(){
	  int sum_ofWL1_WLn =0 ;
	 for(i=0;i<counter0 /* Дължината на стринга до звездичката .*/;i++){
	    	 	int counter2 = 0,i_2 = 0 ;
			   		  if(str1_2[i] != ' ' || str1_2[i] != '.'){
				           counter2 ++;
				     	   counter2 = i_2; /*promneliva int durjashta broq simvoli*/ 
				     	         if(word_lenght[i] != 0){
				     	           	i_2 = i_2 - sum_ofWL1_WLn ;
				     	           	word_lenght[i] = i_2;
							      }
							     else{
								     word_lenght [i] = i_2;
						              counter2 = 0 ;
							     }
					  }
					  else {
					          str1_2 [i] = '*';
					       }
						sum_ofWL1_WLn += word_lenght[i]	;   
		    }
	 	    
}
void longestWord (){
	int d =0 /*count the stars(case 3)*/ ,cicle_counter = 0,pos_of_max_w_lenght = 0,sum  = 0;
	int  sumbols_bevore_max_lenght = 0,max_w_lenght = 0;
	int num_of_stars[30000];
	
	for(i= cicle_counter; i < counter0 /* Дължината на стринга до звездичката .*/;i++ ) {
							      		while(str1_2 [i] == '*' && str1_2 [i +1 ] == '*'){
							      	             	d ++ ; /*count the stars(case 3)*/
									             }
									    for(i=0;i<30000;i++){
							      			    num_of_stars[i] = d + 1 ;
										        }
									   d = 0;    
								       str1_2 [i] = cicle_counter ;
						            i = cicle_counter;
	}
	                    
	                    
	                    
	                    
            for(i=0;i<15000;i++){  //namiram broqt simvoli na naj-dulgata duma
			      if(word_lenght[i] > max_w_lenght){
			    	max_w_lenght = word_lenght[i];
			      }	
			}
            
            for(i=0;i< 15000;i++){
            	   if(max_w_lenght != word_lenght[i]){
            	   	pos_of_max_w_lenght ++ ;
				   }
			    }
		 
		   for(i=0;i< pos_of_max_w_lenght ;i++){
            	   sum += word_lenght[i];
			    }
		   sumbols_bevore_max_lenght = sum - max_w_lenght;
		
		 
		    for( i = sumbols_bevore_max_lenght ; i< sum ;i++ ) {
		    	printf("The longest word is  %c",str1_2[i]);
			}
}

void nov_red(FILE * fptxt,FILE * fptxt1){
	  int a;
	  char str_nov_red[15000][20];
		if((fptxt = fopen("text.txt ","rb+")==NULL)) {
	     	printf("Cannot open file.\n");
	    	exit(1);
            }
               if((fptxt = fopen("text1.txt ","wb+")==NULL)) {
	     	printf("Cannot open file.\n");
	    	exit(1);
            }
            
           for (i = 0 ; i < 15000 ; i++) {
           	int c = 0;
           	strncpy (str_nov_red[i][20],str1_3, word_lenght[i]);
           	    for(a = 0 ;a<1500;a++)/* a case3_for_stars*/{
           	   	   str1_3[ 0 + num_of_stars[a]];
			     }
		   }
            
           fputs(str_nov_red,fptxt1);
           fclose(fptxt);
           fclose(fptxt1);
}


void print_file(FILE * fptxt1){
	  char str_nov_red[15000][20];
	  if((fptxt1 = fopen("text.txt ","r")==NULL)) {
	     	printf("Cannot open file.\n");
	    	exit(1);
            } 
             while (fscanf(fptxt1, "%s",str_nov_red)!=EOF)
                   printf("%s",str_nov_red);
             fclose(fptxt1);
}
