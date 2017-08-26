# include<stdio.h>
int main (){
float dist ,speed;
int num;

printf("Enter  number of drive time  computations: *");
scanf("%d",& num);

for(;num; num--) {
	printf("*\n enter distance:");
	scanf("%f", & dist);
	
	printf("enter average speed : ");
	scanf("%f", &speed);
	printf("Drive time is %f\n ", dist/speed);	
}
return 0 ;
}
