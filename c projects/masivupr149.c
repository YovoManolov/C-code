/*programata `chete dnevnata temperatura za vseki den ot meseca
i sled towa dokladwa sredno- mesechnata temperatra , nai-goreshtiq i 
nai-studenie den 
*/
#include <stdio.h>
#include <stdlib.h>

    float averagetemp (int days,FILE *temp){
    float sum = 0.000 ,average_temp, day_temp[32];
    int i = 0; 
    if((temp = fopen("temp_file.txt","r+"))==NULL){
    	printf("Cannot open file - Error !!! \n");
    	exit(1);
	}		
	 fread(day_temp, sizeof(day_temp)+1, 1,temp);
	for(i=0 ;i<days ;i++) {
		sum += day_temp[i];
	}
   		average_temp = (float) sum /days ;
   		fclose(temp);
	return average_temp;
}
float maxtemp(int days,FILE *temp){
	int i;
   float max = 0.000, day_temp[32];
	if((temp = fopen("temp_file.txt","r+"))==NULL){
    	printf("Cannot open file - Error !!! \n");
    	exit(1);
    }
    
     fread(day_temp, sizeof(day_temp)+1, 1,temp);
    	for(i=0;i<days ;i++) {
    		if(max<day_temp[i]){
    			max = day_temp[i];
			}
		}
 return max;		
}

float mintemp(int days,FILE *temp){
   float min = 99999.999, day_temp[32];
   int i ;
	if((temp = fopen("temp_file.txt","r+"))==NULL){
    	printf("Cannot open file - Error !!! \n");
    	exit(1);
    }
     fread(day_temp, sizeof(day_temp), 1,temp);
    		for(i=0;i<days;i++) {
    		if(min>day_temp[i]){
    			min = day_temp[i];
			}
		}
return min;
}
		
int main (){
	FILE *temp;
	float day_temp[10];
    int days ,i;
    
	printf("Enter number of days: \n");
    scanf("%d",&days);
    
		if((temp = fopen("temp_file.txt","w+"))==NULL){
			printf("Cannot open file - Error !!! \n");
			exit (1);
		} 
			for(i=0;i<days;i++){
				printf("Enter temperature for day  %d:" , i+1);
				scanf("%f",&day_temp[i]);
			}
		fwrite(day_temp,sizeof(day_temp),1,temp);
		fclose(temp);	
		printf(" The average temp for %d days is  %f", days , averagetemp(days,temp));
		printf(" The max temp for %d days is  %f", days , maxtemp(days,temp));
		printf(" The min temp for %d days is  %f", days , mintemp(days,temp));
		
	
	return 0;
}


