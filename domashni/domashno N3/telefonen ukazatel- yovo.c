#include<stdio.h>
#include<string.h>
#include<ctype.h>

void strToUpper(char* name){
	int j;
	for(j = 0; j < strlen(name); j++){
			if(islower(name[j])){
				name[j] = toupper(name[j]);
			}
		}
}

int main () {
	char names [30][20],nums [30][20];
	char searchName [20];
	int i=0 ,j,choice,c;
	
	for(i = 0; i <17; i++){
		printf("Enter name %d: ", i+1);
		fgets(names,strlen(string)+1,names);
		strToUpper(names[i]);
		printf("Enter number: ");
		fgets(nums,strlen(string)+1,numbers);
	}
	 
	 printf("Please choose from the menu below...");

 
     printf("1. Search a contact");
     printf("2. Save new contact");
      printf("3. Delete contact");
     printf("4. Exit");

    // Get and store their choice
    int choice = 0;
    scanf("%d", &choice)

    // Evaluate teh choice and call the selected functions

    switch (choice) {
        case 1:

            printf("Choice 1 selected");

            break;

       case 2:

            printf("Choice 2 selected");

            break;

        case 3:

            printf("Choice 3 selected");

            break;

        default:

            printf("Choice 4 selected");

       	if(choice == 1 ){
	      	printf("Enter name to search(exit for exit): ");
	     	gets(searchName);
		    if(!strcmp(searchName, "exit")){
			     break;
		         }
		    strToUpper(searchName);
		    flag = 0;
		               for(i = 0; i < 30; i++)if(strcmp(searchName == names[i])) printf("%d" , flag=1);
			           else flag = 0;
			                    if (flag = 1) pritnf("Searched name is %c", names[i]);
		               }
		if(flag = 0){
			printf("NOT FOUND\n");
	
                      }
         if(choice == 2 ){
	      	printf("Enter name %d: ", i+1);
		gets(names[i]);
		strToUpper(names[i]);
		printf("Enter number: ");
		gets(nums[i]);
		                           }
		if (choice ==3){
			
			
		}                          
	
                      }             
               
       }
       

