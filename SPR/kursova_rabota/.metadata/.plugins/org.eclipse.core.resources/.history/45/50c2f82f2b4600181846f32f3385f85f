/*
    C ECHO client example using sockets
*/
#include "client.h"

void printMenu(){
	printf("Please enter your choice from the menu! \n");
   	printf("\n\n---------MENU---------");
   	printf("\n1.Всички мои пътувания");
   	printf("\n2.Добави ново пътуване");
   	printf("\n3.Намери пътуване по дата на тръгване");
   	printf("\n4.Изведи 10-те най-дълги пътувания");
   	printf("\n5.Изведи 10-те най-къси пътувания");
   	printf("\n6.Изчисти екарана");
   	printf("\n7.Изход\n\n");
}
 
void clearScreen(){
	char c;
	printf("If you want to clear the screen press Y !");
	c = getchar();
	if(c == 'Y' || c == 'y'){
		printf("\033[H\033[J");
	}
}

void readMessageFromServer(int sock,char* server_message, int sizeOfMessage){
	if(recv(sock , server_message ,500, 0) < 0){
		 puts("recv failed");
	}else{
		 printf("%s\n",server_message);
	}
	memset(server_message, 0, 500);
}

int addNewTrip(int sock,char* server_message) {
	char place_name[50],date[12];
    double lon,lat;

				  //------------------------------------------
			      //------------------------------------------
			      //BEGINNING
			      //------------------------------------------
    			  //------------------------------------------

				  readMessageFromServer(sock,server_message,sizeof(server_message));
		          scanf("%lf",&lon);
		          if(send(sock ,&lon , sizeof(double) , 0) < 0)
			      {
			         puts("Sending beg longitude failed");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------
				  readMessageFromServer(sock,server_message,sizeof(server_message));
		          scanf("%lf",&lat);
		          if(send(sock ,&lat , sizeof(double) , 0) < 0)
			      {
			         puts("Sending beg latitude failed");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------

				  readMessageFromServer(sock,server_message,sizeof(server_message));
		          scanf("%s",place_name);
		          if(send(sock , place_name , strlen(place_name) , 0) < 0)
			      {
			         puts("Sending beg starting position name failed");
			     	 return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------

				  readMessageFromServer(sock,server_message,sizeof(server_message));
		          scanf("%s",date);
		          if(send(sock ,date , strlen(date) , 0) < 0)
			      {
			         puts("Sending beg starting position name failed");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------
			      //DESTINATION
				  //------------------------------------------
			      //------------------------------------------
				  readMessageFromServer(sock,server_message,sizeof(server_message));
		          scanf("%lf",&lon);
		          if(send(sock , &lon , sizeof(double) , 0) < 0)
			      {
			         puts("Sending destination longitude failed");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------
				  readMessageFromServer(sock,server_message,sizeof(server_message));
		          scanf("%lf",&lat);
		          if(send(sock ,&lat , sizeof(double) , 0) < 0)
			      {
			         puts("Sending destination latitude failed");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------
				  readMessageFromServer(sock,server_message,sizeof(server_message));
		          scanf("%s",place_name);
		          if(send(sock ,place_name, strlen(place_name) , 0) < 0)
			      {
			         puts("Sending destination starting position name failed!\n");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------
				  readMessageFromServer(sock,server_message,sizeof(server_message));
		          scanf("%s",date);
		          if(send(sock ,date , strlen(date) , 0) < 0)
			      {
			         puts("Sending destination starting position name failed!\n");
			         return 1;
			      }
			      //-------------------------------------------
			      //-------------------------------------------

}


int main(int argc , char *argv[])
{
    int sock,menu_choice,f_returnVal;
    struct sockaddr_in server;
    char server_message[500];


    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8889);

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    //keep communicating with server
    while(1)
    {
    	printMenu();
    	scanf("%d",&menu_choice);
        if(send(sock ,&menu_choice , sizeof(int) , 0) < 0)
        {
           puts("Menu choice sending failed");
           return 1;
        }

        readMessageFromServer(sock,server_message,sizeof(server_message));

        switch(menu_choice){
        	case 1:
				break;
			case 2:
				if(1 == addNewTrip(sock,server_message)){
					return 1;
				}
			    clearScreen();
			    printMenu();
				break;
			case 3: 
				break;
			case 4: 
				break;
			case 5:
				break;
			case 6:
				clearScreen();
				break;
			case 7:
				exit(0);
				break;
			default:
				break;

		}

    }
     
    close(sock);
    return 0;
}
