#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int fd;

	char * myfifo = "/home/yovo/Documents/myCode/tempFiles/Some content.txt";

	mkfifo(myfifo, 0666);

	char arr1[80],arr2[80];
	while(1){
		//OPEN fifo for write only
		fd = open(myfifo, O_WRONLY);

		//Take an input arr2Int from user
		//80 max length
		fgets(arr2,80,stdin);

		//write the input arr2ing on FIFO 
		//and close it 
		write(fd, arr2,strlen(arr2)+1);
		close(fd);

		//Open FIFO for Read only
		fd = open(myfifo, O_RDONLY);

		//READ from fifo
		read(fd, arr1, sizeof(arr1));

		//Print the read message
		printf("User2: %s\n",arr1);
		close(fd);
	}
	return 0;
}
