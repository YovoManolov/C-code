#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>


typedef struct calcStr{
	char x;
	int a;
	int b;
}calcStr_t;


int main(){
	int fd;
	double result;
	calcStr_t str;

	char * myfifo = "/tmp/myfifo2";
	unlink(myfifo);
	mkfifo(myfifo,0666);

	printf("Enter operation: + ,-,* ,/ \n");
	scanf("%c",&str.x);
	printf("Enter a : " );
	scanf("%d",&str.a);
	printf("\nEnter b : " );
	scanf("%d",&str.b);

	fd = open(myfifo, O_WRONLY);
	if(!fd) perror("open:");
	if (0 > write(fd,&str, sizeof(calcStr_t)))
		perror("write:");
	close(fd);

	fd = open(myfifo, O_RDONLY);
	if(!fd) perror("open2:");
	if (0 > read(fd,&result,sizeof(double)))
		perror("read:");
	printf("\nResult from a %c b = %lf ",str.x, result);

	close(fd);
	unlink(myfifo);

	return 0;
}


