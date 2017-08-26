//sytax int fread(void *Bufer, int Size, int Count, File *ptr);
/*float x;
FILE *fptr;
int fread (&x, sizeof (x),1 ,fptr);

*/

struct student {
	char name [50];
	int roll;

};
main(){
	FILE *fptr;
	struct sudent st[20];
	int num;
	if ((fptr = fopen("ip.txt","wb+"))== NULL)
	{
		printf("\n Error in Opening File");
		exit(0);
		}
		printf("How many students : ");
		scanf("%d",&num);
		 
		 for(i=0;i<num;i++){
		 	printf("\n Enter the name and row number ");
		 	scanf("%s,%d",st.name,&st.row);
		 	fwrite(&st,sizeof(st),1,fptr);	
		 }
		 //structure is written on file
		 //now read file
		 if((fptr =fopen("io.txt","rb"))=NULL)
		 {
		 	printf("\nError in Opening File");
		 	exit (0);
		 }
	while ((fwrite(&st,sizeof(st),1,fptr)))	{
		printf("\nName : %s",st.name);
		printf("\nRoll:%d",st.roll);
	}
	fclose();
	getch();
		 
}
