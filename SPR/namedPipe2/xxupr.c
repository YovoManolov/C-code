#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

main(){
	
	FIFO *file1;
	int fifo_server,fifo_client;
	char *choice;
	// fork() : in the original process fork 
	// returns PID of the child
	// process. The child process returns 0;

	if(fork() == 0){
		while(1){
			choice = malloc(10 * sizeof(char));
			scanf("%s",choice);

			fifo_server = open("fifo_server",O_RDWR);
			if(fifo_server <_1){
				printf("Error in opening file");
				exit(-1);

			}

			write(fifo_server,choice,sizeof(choice));
			//sleep(10);
		}
	}else{
		while(1){
			 fifo_client = open("fifo_client",O_RDWR);
		     if(fifo_client<1) {
		         printf("Error opening file");
		         exit(1);
		     }

		     read(fifo_client,choice,sizeof(choice));
		     printf("%s\n",choice);
		}
	}

	close(fifo_server);
	close(fifo_client);
}