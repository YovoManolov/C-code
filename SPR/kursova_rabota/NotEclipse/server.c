 //for threading , link with lpthread

#include "server.h"
 /// https://www.binarytides.com/server-client-example-c-sockets-linux/

int main(int argc , char *argv[]){
	int socket_desc, client_sock,c , *new_sock;
	struct sockaddr_in server , client ;

	//create socket 
	socket_desc = socket(AF_INET ,SOCK_STREAM, 0);
	if( socket_desc  == -1) {
		printf("Could not create socket" );

	}
	puts("Socket created");

	server.sin_family = AF_INET ;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8889);

	if(bind(socket_desc,(struct sockaddr*)&server ,sizeof(server)) < 0){
		//print the errror message
		perror("bind failed. Error");
		return 1;
	}
	puts("bind done");

	//listen
	listen(socket_desc, 3);

	puts("Waiting for incomming connections...");
	c = sizeof(struct sockaddr_in);

	//waiting client to choose form menu.
 	while( (client_sock = accept(socket_desc, 
 					(struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");
         
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;
        
        if( pthread_create(&sniffer_thread , NULL ,
        					connection_handler , (void*) new_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        pthread_join( sniffer_thread , NULL);
        puts("Handler assigned");
    }
     
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
}

//to handle connection for each thread 
void* connection_handler(void * socket_desc){
	int sock= *(int*) socket_desc,message_size;
	int menu_choice ,read_size;
	char *greeting;
	Travel t;
	
	greeting = "Hi client! I am your connection handler\0";
	message_size = strlen(greeting);
	write(sock,&message_size,sizeof(int));
	write(sock, greeting,strlen(greeting));

	//recv returns -1 on error and number of bites received on success
	while((read_size = recv(sock,&menu_choice,sizeof(int),0)) != -1){
		
		switch(menu_choice){

			case 1:
				break;
			case 2: 
				loadTravelInfo(socket_desc,&t);
				
				printf("beg longitude %lf \n",t.beginning.Lon);
				printf("beg latitude %lf \n", t.beginning.Lat);
				printf("beg name %s \n", t.beginning.name);
				printf("beg date %s \n", t.beginning.date);
				printf("dst longitude %lf \n", t.destination.Lon);
				printf("dst latitude %lf \n", t.destination.Lat);
				printf("dst name %s \n", t.destination.name);
				printf("dst date %s \n", t.destination.date);
				printf("The distance of your trip is :%lf",t.distance);
				break;
			case 3: 
				break;
			case 4: 
				break;
			case 5:
				break;
			default:
				printf("Client choice was invalid!");
				break;

		}
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

void loadTravelInfo(void* socket_desc,Travel* t){
	int sock = *(int*) socket_desc ,message_size;
	double Lon, Lat;
	int read_size;
	char* ascForInput,place_name[50], date[12];

	//=============================
	//start-longit
	//=============================
	ascForInput = "Please enter Longitude of starting position:\0";
	message_size = strlen(ascForInput);
	write(sock,&message_size,sizeof(int));
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,&Lon,sizeof(double),0)) < 0){
		perror("Error reading start pos Longitude!:  ");
	}else{
		t->beginning.Lon = Lon;
	}


	//=============================
	//start-latit
	//=============================
	ascForInput = "Please enter Latitude of starting position:\0";
	message_size = strlen(ascForInput);
	write(sock,&message_size,sizeof(int));
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,&Lat,sizeof(double),0)) < 0){
		perror("Error reading start pos Latitude!:  ");
	}else{
		t->beginning.Lat = Lat;
	}


	//=============================
	//start-name
	//=============================
	ascForInput = "Please enter name of starting position:\0";
	message_size = strlen(ascForInput);
	write(sock,&message_size,sizeof(int));
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,place_name,50,0)) < 0){
		perror("Error reading start pos name!:  ");
	}else{
		strcpy(t->beginning.name,place_name);
	}

	//=============================
	//start-date
	//=============================
	ascForInput = "Please enter date of departure like dd/mm/yyyy:\0";
	message_size = strlen(ascForInput);
	write(sock,&message_size,sizeof(int));
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,date,12,0)) < 0){
		perror("Error reading departure date!:  ");
	}else{
		strcpy(t->beginning.date, date);
	}


	//=============================
	//dest-longit
	//=============================
	ascForInput = "Please enter Longitude of destination:\0";
	message_size = strlen(ascForInput);
	write(sock,&message_size,sizeof(int));
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,&Lon,sizeof(double),0)) < 0){
		perror("Error reading destination Longitude!:  ");
	}else{
		t->destination.Lon = Lon;
	}

	//=============================
	//dest-latit
	//=============================
	ascForInput = "Please enter Latitude of destination:";
	message_size = strlen(ascForInput);
	write(sock,&message_size,sizeof(int));
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,&Lat,sizeof(double),0)) < 0){
		perror("Error reading destination Latitude!:  ");
	}else{
		t->destination.Lat = Lat;
	}

	//=============================
	//dest-name
	//=============================
	ascForInput = "Please enter name of destination position:\0";
	message_size = strlen(ascForInput);
	write(sock,&message_size,sizeof(int));
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,place_name,50,0)) < 0){
		perror("Error reading start pos name!:  ");
	}else{
		strcpy(t->destination.name,place_name);
	}

	//=============================
	//dest-date
	//=============================
	ascForInput = "Please enter date of arrival like dd/mm/yyyy:\0";
	message_size = strlen(ascForInput);
	write(sock,&message_size,sizeof(int));
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,date,12,0)) < 0){
		perror("Error reading arrival date!:  ");
	}else{
		strcpy(t->destination.date, date);
	}

	t->distance = distance(t->beginning.Lon,t->beginning.Lat,t->destination.Lon,t->destination.Lat,'K');
}

double deg2rad(double degrees){
	return (degrees) * PI / 180.0;
}

double rad2deg(double radians){
	return (radians) * 180.0 / M_PI ;
}

double distance(double lat1, double lon1, double lat2, double lon2, char unit) {
  double theta, dist;
  theta = lon1 - lon2;
  dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1))
  								* cos(deg2rad(lat2)) * cos(deg2rad(theta));
  dist = acos(dist);
  dist = rad2deg(dist);
  dist = dist * 60 * 1.1515;
  switch(unit) {
    case 'M':
      break;
    case 'K':
      dist = dist * 1.609344;
      break;
    case 'N':
      dist = dist * 0.8684;
      break;
  }
  return (dist);
}