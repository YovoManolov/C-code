//SYNTAX :
// int fwrite(void *Buffer , int Size , int Count , FILE *ptr );
/**
Buffer” is Variable of Pointer Type.
“Buffer” Holds Starting Address of the Block
 to be Written on File.
Size Specifies the Size in Bytes of Individual Data Item.
Count Specifies “Number of Items to Be Written Onto File“.

Examples :
1 . write variale x of type FLoat to file 
 
 
 float x;
 FILE *fptr;
 int fwrite(&x,sizeof(x),1,fptr);
*/
// ARRAY of 100 elements
/* float x[100];
FILE *fptr
int fwrite(&x,sizeof(x),100,fptr );
*/
struct student {
	char name [50];
	int roll;
};
main() {
	FILE*fptr
	struct student st[20];
	int num ;
	if((fptr = fopen("ip.txt","wb+"/* create binary
	 file for writing and save*/))== NULL){
		printf("nError int Opening file");
		exit(0);
		
	}
	printf("how many students: ");
	scanf("%d",&num);
	
	for (i=0;i<num;i++){

	printf("\n ENTER the name and roll number");
	scanf("%s %d, st.name , &st.roll");
	fwrite(&st,sizepf(st),1,fptr);
}
//Structure is Written of File 
getch ();
	
}







