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
 


int main(int argc , char *argv[])
{
    int sock,menu_choice,server_message_length;
    struct sockaddr_in server;
    char server_message[500], place_name[50],date[12];
    double lon,lat;

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

        if(recv(sock ,&server_message_length ,sizeof(int), 0)<0){
				puts("recv failed");
		        break;
		}
		if(recv(sock , server_message ,server_message_length, 0) < 0){
       		  puts("recv failed");
       		  break;
       	}else{
       		  printf("%s\n",server_message);
       	}

        switch(menu_choice){
        	case 1:
				break;
			case 2: 

				  //------------------------------------------
			      //------------------------------------------
			      //BEGINNING
				  //------------------------------------------
			      //------------------------------------------

				 if(recv(sock ,&server_message_length ,sizeof(int), 0)<0){
				 	puts("recv failed");
		            break;
				 }
				 if(recv(sock , server_message ,server_message_length, 0) < 0){
		            puts("recv failed");
		            break;
		          }else{
		        	 printf("%s\n",server_message);
		          }
		          scanf("%lf",&lon);
		          if(send(sock ,&lon , sizeof(double) , 0) < 0)
			      {
			         puts("Sending beg longitude failed");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------
			      if(recv(sock ,&server_message_length ,sizeof(int), 0)<0){
				 	puts("recv failed");
		            break;
				 }
				 if(recv(sock , server_message ,server_message_length, 0) < 0){
		            puts("recv failed");
		            break;
		          }else{
		        	 printf("%s\n",server_message);
		          }
		          scanf("%lf",&lat);
		          if(send(sock ,&lat , sizeof(double) , 0) < 0)
			      {
			         puts("Sending beg latitude failed");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------
			     if(recv(sock ,&server_message_length ,sizeof(int), 0)<0){
				 	puts("recv failed");
		            break;
				 }
				 if(recv(sock ,&server_message ,server_message_length, 0) < 0){
		            puts("recv failed");
		            break;
		          }else{
		        	 printf("%s\n",server_message);
		          }
		          scanf("%s",place_name);
		          if(send(sock , place_name , strlen(place_name) , 0) < 0)
			      {
			         puts("Sending beg starting position name failed");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------
			      if(recv(sock ,&server_message_length ,sizeof(int), 0)<0){
				 	puts("recv failed");
		            break;
				 }
				 if(recv(sock , server_message ,server_message_length, 0) < 0){
		            puts("recv failed");
		            break;
		          }else{
		        	 printf("%s\n",server_message);
		          }
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
			      if(recv(sock ,&server_message_length ,sizeof(int), 0)<0){
				 	puts("recv failed");
		            break;
				 }
				 if(recv(sock , server_message ,server_message_length, 0) < 0){
		            puts("recv failed");
		            break;
		          }else{
		        	 printf("%s\n",server_message);
		          }
		          scanf("%lf",&lon);
		          if(send(sock , &lon , sizeof(double) , 0) < 0)
			      {
			         puts("Sending destination longitude failed");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------
			   	 if(recv(sock ,&server_message_length ,sizeof(int), 0)<0){
				 	puts("recv failed");
		            break;
				 }
				 if(recv(sock , server_message ,server_message_length, 0) < 0){
		            puts("recv failed");
		            break;
		          }else{
		        	 printf("%s\n",server_message);
		          }
		          scanf("%lf",&lat);
		          if(send(sock ,&lat , sizeof(double) , 0) < 0)
			      {
			         puts("Sending destination latitude failed");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------

			     if(recv(sock ,&server_message_length ,sizeof(int), 0)<0){
				 	puts("recv failed");
		            break;
				 }
				 if(recv(sock , server_message ,server_message_length, 0) < 0){
		            puts("recv failed");
		            break;
		          }else{
		        	 printf("%s\n",server_message);
		          }
		          scanf("%s",place_name);
		          if(send(sock ,place_name, strlen(place_name) , 0) < 0)
			      {
			         puts("Sending destination starting position name failed!\n");
			         return 1;
			      }
			      //------------------------------------------
			      //------------------------------------------
			     if(recv(sock ,&server_message_length ,sizeof(int), 0)<0){
				 	puts("recv failed");
		            break;
				 }
				 if(recv(sock , server_message ,server_message_length, 0) < 0){
		            puts("recv failed");
		            break;
		          }else{
		        	 printf("%s\n",server_message);
		          }
		          scanf("%s",date);
		          if(send(sock ,date , strlen(date) , 0) < 0)
			      {
			         puts("Sending destination starting position name failed!\n");
			         return 1;
			      }
			      //-------------------------------------------
			      //-------------------------------------------
			    clear();
				break;
			case 3: 
				break;
			case 4: 
				break;
			case 5:
				break;
			case 6:
				clear();
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
