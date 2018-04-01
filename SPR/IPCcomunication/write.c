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

	fd = open(myfifo, O_RDONLY);
	if(!fd) perror("open:");


		if (0 > read(fd, &str, sizeof(calcStr_t)))
			perror("read:");
		
		printf("Resieved vars : ");
		printf("a %d : ", str.a);
		printf("b %d : ", str.b);
		printf("operation: %c : ", str.x);

		switch(str.x){
			case '+':
				result = str.a + str.b;
				break;
			case '-':
				result = str.a - str.b;
				break;
			case '*':
				result = str.a * str.b;
				break;
			case '/':
				result = str.a / str.b;
				break;			
		}
		close(fd);

		printf("Sending response: \n");
		fd = open(myfifo, O_WRONLY);
		if(!fd) perror("open2:");
		if ( 0 > write(fd, &result, sizeof(double)))
			perror("write:");


	close(fd);
	return 0;

}
