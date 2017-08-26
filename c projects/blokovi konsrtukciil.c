# include <stdio.h>
int main(void)
{
	float num;
	int choice;
	
	printf("1: Feet to Meter,2: Meter to Feet.");
	printf("Enter choice: ");
	scanf("%d", &choice) ;
	
	if(choice == 1) {
		printf("enter a number of feet : ");
		scanf("%f", &num);
		printf("meters: %f", num/3.28);
		
	}
	else{
		printf("enter number of meters: ") ;
        scanf("%f",&num);
        printf("Feet: %f", num*3,28);
	}
	return 0;
}
