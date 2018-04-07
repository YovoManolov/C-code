#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>    
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h> //for threading , link with lpthread

 /// https://www.binarytides.com/server-client-example-c-sockets-linux/

typedef struct place {
   double Lon; 
   double Lat;
   char name[50];
   char date[12]; //dd-mm-yyyy
} Place ;

typedef struct travel {
   Place beginning;
   Place destination;
   Travel* next;
} Travel;

typedef struct tourist {
   char name[20];
   int countOfTravels; //id of last added travel
   					   //starting from 1 to n
   Travel* headNode;
} Tourist;

void *connection_hadnler(void*);

int main(int argc , char *argv[]){
	int socket_desc, client_sock,c , *new_sock;
	struct sockaddr_in server , client ;

	//create socket 
	socket_desc = socket(AF_INET , SOCKET_STREAM , 0);
	if( socket_desc  == -1) {
		printf("Could not create socket" );

	}
	puts("Socket created");

	server.sin_family = AF_INET ;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port( 8889 );

	if(bind(socket_desc,(struct sockaddr*)*server ,sizeof(server)) < 0){
		//print the errror message
		perror("bind failed. Error");
		return 1;
	}
	puts("bind done");

	//listen
	listen(socket_desc, 3);

	puts("Waiting for incomming connections...");
	c = sizeof(struct sockaddr_in);

 	while( (client_sock = accept(socket_desc, 
 					(struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");
         
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;
         
        if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL);
        puts("Handler assigned");
    }
     
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
}

//to handle connection for each thread 
void * connection_handler(void * socket_desc){
	int sock= *(int*) socket_desc;
	int menu_choice;
	char *greeting, *enterChoice, clent_message[2000];


	greeting = "Hi client! I am your connection handler\n";
	write(sock, greeting,strlen(greeting));

	enterChoice = "Now enter your choice from the menu \n";
	
	char* menu = 
	"\n\n1.Всички мои пътувания\n
	 2.Добави ново пътуване\n
	 3.Изведи 10-те най-дълги пътувания\n
	 4.Изчисти екарана\n
	 5.Изход\n";

	write(sock, enterChoice ,strlen(message));
	write(sock, menu ,strlen(menu));
	//receive message from client
	//recv returns -1 on error and number of bites received on success
	while((read_size = recv(sock,menu_choice,sizeof(int),0)) < 0){
		//Send message back to client
		switch(menu_choice){

			case 1: showAllTravels();
				break;
			case 2: 
				Travel t = loadTravelInfo();
				addNewTravel(Travel t);
				break;
			case 3: printTenLongestTravels();
				break;
			case 4: clearScreen();
				break;
			case 5: exit();
				break;
			default:
				break;

		}
		//write(sock, client_message, strlen(client_message));
	}

	if(read_size == 0){
		puts("Client disconnected");
		fflush(stdout);
	}
	else if(read_size == -1){
		perror("recv failed");
	}

	free(socket_desc);
}

Travel loadTravelInfo(){
	Travel t;
	double Lon, Lat;
	char* ascForInput,place_name[50], date[12];

	ascForInput = "Please enter Longitude of starting position:";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,Lon,sizeof(double),0)) < 0){
		perror("Error reading start pos Longitude!:  ");
	}else{
		t->beginning->Lon = Lon;
	}

	ascForInput = "Please enter Latitude of starting position:";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,Lat,sizeof(double),0)) < 0){
		perror("Error reading start pos Latitude!:  ");
	}else{
		t->beginning->Lat = Lat;
	}

	ascForInput = "Please enter name of starting position:";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,place_name,50,0)) < 0){
		perror("Error reading start pos name!:  ");
	}else{
		strcpy(t->beginning->name,place_name);
	}

	ascForInput = "Please enter date of departure like dd/mm/yyyy: ";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,date,12,0)) < 0){
		perror("Error reading departure date!:  ");
	}else{
		strcpy(t->beginning->date, date);
	}

	ascForInput = "Please enter Longitude of destination:";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,Lon,sizeof(double),0)) < 0){
		perror("Error reading destination Longitude!:  ");
	}else{
		t->destination->Lon = Lon;
	}

	ascForInput = "Please enter Latitude of destination:";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,Lat,sizeof(double),0)) < 0){
		perror("Error reading destination Latitude!:  ");
	}else{
		t->destination->Lat = Lat;
	}


	ascForInput = "Please enter name of destination position:";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,place_name,50,0)) < 0){
		perror("Error reading start pos name!:  ");
	}else{
		strcpy(t->destination->name,place_name);
	}

	ascForInput = "Please enter date of arrival like dd/mm/yyyy: ";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,date,12,0)) < 0){
		perror("Error reading arrival date!:  ");
	}else{
		strcpy(t->destination->date, date);
	}
}

void addNewTravel(Travel t);

void showAllTravels();