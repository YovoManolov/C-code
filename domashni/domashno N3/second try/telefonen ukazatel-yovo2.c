

 #include<stdio.h>
 #include<string.h>

void strToUpper	(char *name){
	int j;
	for(j=0; j < ((strlen)-1); j++){
		if( islower(name[j])){
		name[j] = toupper(name[j]);
	   }
	}
}

int main(){
   FILE *fpName ,*fpNew,*fpNumber, *fpdline2 ;
   int i,r,n,delete_line, temp = 1,temp1 = 1;
   char name[25][20], number[25][20];
	char searched_name [20];
	char ch ;// (case 3);
	/*if ((fp=fopen("rand","wb"))== NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}*/
	 if(fpName = fopen(("namef.txt ","w")==NULL)) {
	        printf("Cannot open file.\n ");
            exit(1);
        }
     if(fpNumber = fopen(("numberf.txt ","w")==NULL)) {
	 printf("Cannot open file.\n ");
            exit(1);
        }
	
	for(i = 0; i <20; i++){
		printf("Enter name %d: ", i+1);
		fputs(name[i][20],fpName);
		strToUpper(name[i]);
		printf("Enter number %d: ", i+1);
		fputs(number[i][20],fpNumber); 
		fclose (fpName);
		fclose (fpNumber);
	}
	 
	
	
	printf("|______________MENU____________|");

 
     printf("|____1.Search a contact_______|");
     printf("|____2. Save new contact______|");
     printf("|____3. Delete contact________|");
     printf("|____4. Exit__________________|");

    // Get and store their choice
    int choice = 0;
    scanf("%d", &choice);

    // Evaluate the choice and call the selected functions

    switch (choice){
        case 1:
            printf("Choice 1 selected");
            if(fpName = fopen(("namef.txt ","r")==NULL)) {
			{
		    printf("FNF!");
		    return 1;
			}
            if(fpNumber = fopen(("numberf.txt","r")==NULL)) {
			printf("Cannot open file.\n ");
            exit(1);
           }
            printf("Enter searched name : %d \n");
			scanf("%c",&searched_name);
			
			      for(r=0;r<20;r++) {
                        if(!strcmp(searched_name,name[r][20])){
                        	fgets(name[r][20],20,fpName);
                        	printf("NAME : c% \t",name[r][20] );
                            r=n;
                            fgets(number[n][20],20,fpNumber);
                            printf("NUMBER : c% \n",number[n][20] );
						}
            fclose (fpName);
		    fclose (fpNumber);
            break;

       case 2:
       	    printf("Choice 2 selected");
              if(fpName= fopen (("namef.txt ","a")==NULL)) {
			   
			  printf("Cannot open file.\n ");
            exit (1);
             }  
              char name[20],number [20];
              printf("Enter name space and number : ");
              scnaf("%c \t %c", &name[i],&number[i]);
              strToUpper(name[i]);
              printf("Enter name %d: ", i+1);
		      fprintf(fpName,"%c",name);
		      strToUpper(name[i]);
		      printf("Enter number %d: ", i+1);
		      fprintf(fpNumber,"%d",number); 
        
            //  fprintf(fpName fpNumber,"%c" "%d" ,name , number);
            // fprintf(fpName,"%c",name);
            //fprintf(fpNumber,"%d",number);

            break;

        case 3:

            printf("Choice 3 selected");

            printf("Enter searched name : \n");
			scanf("%s",&searched name);
			
			      for(r=0;r<20;r++) {
                        if(!strcmp(searched_name,name[r][20])) {
                        	                   // *fpdline1, *fpdline2 (recycle_bin_temp)
                        	                   printf("This is the  number of the line you wont to delete : %d", r );
                        	                   r=n;
                        	                         if( fpName = fopen (("namef.txt ","r")==NULL)){
											  
											          printf("Cannot open file.\n ");
											         
										              }
                        	                   ch = getc(fpName);
 `                                              while (ch != EOF)
                                               {
                                                 printf("%c", ch);
                                                 ch = getc(fpName);
                                               }
                                               rewind(fpdline1);
                                               printf(" \n Enter line number of the line to be deleted:");
                                               scanf("%d", &delete_line);
                                               
					                           if(fpdline2 = fopen (("recycle_bin_temp.txt ","w")==NULL)){
											   printf("Cannot open file.\n ");
										      }
                                               ch = getc(fpName);
                                               while (ch != EOF)
                                               {
                                                 ch = getc(fpdline1);
                                                 if (ch == '\n')
                                                          temp++;
                                                          //except the line to be deleted
                                                           if (temp != delete_line)
                                                          {
                                                           //copy all lines in file replica.c
                                                           putc(ch, fpdline2);
                                                          }
                                                }
											     fclose(fpName);
                                                 fclose(fpdline2);
                                                 remove(fpName);
                                                 rename("recycle_bin_temp.txt",namef.txt);
                                                 
                                                // -----------------
                                                //------------------
                                                fpNumber = fopen (("number.txt ","r")==NULL) printf("Cannot open file.\n ");
                                                ch = getc(fpNumber);
                                                while (ch != EOF)
                                               {
                                                printf("%c", ch);
                                               ch = getc(fpNumber);
                                               }
                                               rewind(fpNumber);
                                               printf(" \n Enter line number of the line to be deleted:");
                                               scanf("%d", &n);
                                               
					                           if(fpdline2 = fopen (("recycle_bin_temp.txt ","w")==NULL)) {
											   printf("Cannot open file.\n ");
									         	}
                                               ch = getc(fpNumber);
                                               while (ch != EOF)
                                               {
                                                 ch = getc(fpNumber);
                                                 if (ch == '\n')
                                                          temp1++;
                                                          //except the line to be deleted
                                                           if (temp1 != delete_line)
                                                          {
                                                           putc(ch, fileptr2);
                                                          }
                                                }
											     fclose(fpNumber);
                                                 fclose(fpdline2);
                                                 remove(numberf.txt);
                                                 rename("recycle_bin_temp.txt",numberf.txt);	  
											   }
            break;

        default:

            printf("Choice 4 selected");
            feof(fpName);
            feof(fpNumber);
          }
 return 0;
} 
