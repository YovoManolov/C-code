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

	int sock= *(int*)socket_desc;
	int menu_choice ,read_size,numberOfTrips;
	char messageToClient[500],touristName[50];
	FILE* fp;
	Travel* allTripsHead;
	Travel* currentTouristHead;
	Travel* singleTravelStorage;
	Travel* statisticsListPointer;

	strcpy(messageToClient ,"Hi client! I am your connection handler");
	write(sock, messageToClient, 500);
	memset(messageToClient, 0, 500);

	strcpy(messageToClient ,"Please enter your name: ");
	write(sock, messageToClient, 500);
	memset(messageToClient, 0, 500);

	if((read_size = recv(sock,touristName,50,0)) < 0){
		perror("Error reading start pos Longitude!:  ");
	}else{
		printf("Thank you %s",touristName);
	}

	// =================================================
	// =================================================
	// Load all travels from file 
	// Extract only those for current Traveller
	// =================================================
	// =================================================

	//TO DO synchronize file usage between threads
	if(loadAllTravelsFromFile(allTripsHead,fp) == 1){
		printf("Loading trips from file has failed! \n");
	}

	if(getCurrentUserTravels(touristName,allTripsHead,
                             	 currentTouristHead) == 1){
		printf("Loading trips from file has failed! \n");
	}
	// =================================================

	//recv returns -1 on error and number of bites received on success
	while((read_size = recv(sock,&menu_choice,sizeof(int),0)) != -1){
		
		switch(menu_choice){

			case 1:
				printTravelsOfCurrentTraveller(currentTouristHead);
				break;
			case 2: 
				singleTravelStorage = malloc(sizeof(Travel));
				receiveNewTravelInfo(socket_desc,singleTravelStorage,touristName);
				printTravel(singleTravelStorage);
				addTravel(currentTouristHead,singleTravelStorage);
				break;
			case 3: 
				break;
			case 4: 
				strcpy(messageToClient ,"Please enter number of trips to be returned : ");
				write(sock, messageToClient, 500);
				memset(messageToClient, 0, 500);
				if((read_size = recv(sock,&numberOfTrips,sizeof(int),0)) < 0){
					perror("Number of trips was not received !:  ");
				}else{
					//2cond arg : bool topShortest
					//if false  : topLongest 
					topWantedDistances(currentTouristHead,false,statisticsListPointer,numberOfTrips);
				}
				//printf("\n4.Изведи 10-те най-дълги пътувания");
				break;
			case 5:
				strcpy(messageToClient ,"Please enter number of trips to be returned : ");
				write(sock, messageToClient, 500);
				memset(messageToClient, 0, 500);
				if((read_size = recv(sock,&numberOfTrips,sizeof(int),0)) < 0){
					perror("Number of trips was not received !:  ");
				}else{
					topWantedDistances(currentTouristHead,true,statisticsListPointer,numberOfTrips);
				}
				//printf("\n5.Изведи 10-те най-къси пътувания");
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


int getListSize(Travel* head){
	int listSize = 1;
	Travel *curr;
	curr = head;
	while(curr->next != NULL){
		listSize += 1;
		curr = curr->next;
	}
	return listSize;
}

//if topShortest is false top longest are filtered
void topWantedDistances(Travel* currentTouristHead,bool topShortest,
	Travel* statisticsListPointer,int countOfTripsToReturn){
	Travel *curr;

	int listSize = getListSize(currentTouristHead);
	if(countOfTripsToReturn  > listSize){
		printf("The traveler is trying to filter more travels than those he made !");
	}

	int distanceArr [listSize][2];  //first column id sec column distance;
	int i,j,swap;
	int *IDsOfWantedTrips;

	IDsOfWantedTrips = malloc(countOfTripsToReturn * sizeof(int));

	curr = currentTouristHead;
	while(curr->next != NULL){
		distanceArr[i][0] = curr->id;
		distanceArr[i][1] = curr->distance;
		i++;
		curr = curr->next;
	}

	if(topShortest){
		// array sorting in ascending order
		for(i=0; i < listSize; i++) {
		    for (j = i+1; j < listSize; j++) {
		       if(distanceArr[i][1] > distanceArr[j][1]){
		           swap = distanceArr[i][1];
		           distanceArr[i][1] = distanceArr[j][1];
		           distanceArr[j][1] = swap;
		       }
		    }
		 } 

	}else{
		// array sorting in descending order
		for(i=0; i < listSize; i++) {
		    for (j = i+1; j < listSize; j++) {
		       if(distanceArr[i][1] < distanceArr[j][1]){
		           swap = distanceArr[i][1];
		           distanceArr[i][1] = distanceArr[j][1];
		           distanceArr[j][1] = swap;
		       }
		    }
		} 
	}

	filteredTravelsById(statisticsListPointer,
				currentTouristHead,IDsOfWantedTrips,countOfTripsToReturn);
	free(IDsOfWantedTrips);
}

void filteredTravelsById(Travel* statisticsListPointer,Travel* currentTouristHead,
								int* IDsOfWantedTrips,int countOfTripsToReturn){
	Travel* curr ; 
	curr = currentTouristHead;
	while(curr->next != NULL){
		for(int i=0 ;i < countOfTripsToReturn ;i++){
			if( (*(IDsOfWantedTrips + i)) == curr->id  ){
			  	addTravel(statisticsListPointer,curr);
			}
		}
		curr = curr->next;
	}

}

void receiveNewTravelInfo(void* socket_desc,Travel* t,char* touristName){
	int sock = *(int*) socket_desc ,message_size;
	double Lon, Lat ,averageSpeed;
	int read_size;
	char* ascForInput,place_name[50], date[12];

	//=============================
	//start-longit
	//=============================
	if(strlen(touristName) > 0 ){
		strcpy(t->touristName, touristName);
	}

	ascForInput = "Please enter Longitude of starting position:\0";
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
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,place_name,50,0)) < 0){
		perror("Error reading start pos name!:  ");
	}else{
		strcpy(t->beginning.name,place_name);
	}
	memset(place_name, 0, 50);
	//=============================
	//start-date
	//=============================
	ascForInput = "Please enter date of departure like dd/mm/yyyy:\0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,date,12,0)) < 0){
		perror("Error reading departure date!:  ");
	}else{
		strcpy(t->beginning.date, date);
	}
	memset(place_name, 0, 12);

	//=============================
	//dest-longit
	//=============================
	ascForInput = "Please enter Longitude of destination:\0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,&Lon,sizeof(double),0)) < 0){
		perror("Error reading destination Longitude!:  ");
	}else{
		t->destination.Lon = Lon;
	}

	//=============================
	//dest-latit
	//=============================
	ascForInput = "Please enter Latitude of destination:\0";
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
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,place_name,50,0)) < 0){
		perror("Error reading start pos name!:  ");
	}else{
		strcpy(t->destination.name,place_name);
	}
	memset(place_name, 0, 50);

	//=============================
	//dest-date
	//=============================
	ascForInput = "Please enter date of arrival like dd/mm/yyyy:\0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,date,12,0)) < 0){
		perror("Error reading arrival date!:  ");
	}else{
		strcpy(t->destination.date, date);
	}
	memset(place_name, 0, 12);

	//=============================
	//average speed
	//=============================
	ascForInput = "Please enter average speed in km/h: \0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,&averageSpeed,sizeof(double),0)) < 0){
		perror("Error reading average speed!:  ");
	}else{
		t->averageSpeed = averageSpeed ;
	}

	// K for distance in kilometer 
	t->distance = distance(t->beginning.Lon,t->beginning.Lat,
							t->destination.Lon,t->destination.Lat,'K');
	//always adding the wast node
	t->averageDuration = (t->distance / t->averageSpeed);
	t->next = NULL;

	printf("Trip was added created successfully ! ");
}

void printTravel(Travel *t){
		char stringToSend [100];
		//!!!!!!!!!!!!!!!!!!!!!!
		//TO BE SENDED TO CLIENT 
		//!!!!!!!!!!!!!!!!!!!!!!

		strcpy(stringToSend ,"---------------------------------");
		write(sock, stringToSend,strlen(stringToSend));

		snprintf(stringToSend, 100, "Traveller : %s \0", t->touristName);
		write(sock, stringToSend,strlen(stringToSend));
		memset(stringToSend, 0, 100);


		snprintf(stringToSend, 100, "beg longitude %lf \0", t->beginning.Lon);
		write(sock, stringToSend,strlen(stringToSend));
		memset(stringToSend, 0, 100);

		snprintf(stringToSend, 100, "beg latitude %lf \0", t->beginning.Lat);
		write(sock, stringToSend,strlen(stringToSend));
		memset(stringToSend, 0, 100);

		snprintf(stringToSend, 100, "beg name %s \0", t->beginning.name);
		write(sock, stringToSend,strlen(stringToSend));
		memset(stringToSend, 0, 100);

		snprintf(stringToSend, 100, "beg date %s \0", t->beginning.date);
		write(sock, stringToSend,strlen(stringToSend));
		memset(stringToSend, 0, 100);

		snprintf(stringToSend, 100, "dst longitude %lf \0",  t->destination.Lon);
		write(sock, stringToSend,strlen(stringToSend));
		memset(stringToSend, 0, 100);

		snprintf(stringToSend, 100, "dst latitude %lf \0", t->destination.Lat);
		write(sock, stringToSend,strlen(stringToSend));
		memset(stringToSend, 0, 100);

		snprintf(stringToSend, 100, "dst name %s \0",t->destination.name);
		write(sock, stringToSend,strlen(stringToSend));
		memset(stringToSend, 0, 100);

		snprintf(stringToSend, 100, "dst date %s \0",t->destination.date);
		write(sock, stringToSend,strlen(stringToSend));
		memset(stringToSend, 0, 100);

		snprintf(stringToSend, 100, "The distance of your trip is :%lf \0",t->distance);
		write(sock, stringToSend,strlen(stringToSend));
		memset(stringToSend, 0, 100);

		strcpy(stringToSend ,"---------------------------------");
		write(sock, stringToSend,strlen(stringToSend));
}

void printTravelsOfCurrentTraveller(Travel* currentTouristHead){
	Travel * curr;
	curr = currentTouristHead;

	int numberOfTrips = getListSize(currentTouristHead);
	write(sock,&numberOfTrips,sizeof(int));

	//no need from touristName check , cose all
	//travels are for the current tourist 
	while(curr->next != NULL){
		printTravel(curr);
    	curr = curr->next;
    }
    printTravel(curr);

}

void addTravel(Travel *_head,Travel* singleTravelStorage){
	Travel *_curr;

	if(_head == NULL){
         _head = singleTravelStorage;
    }else{
        _curr = _head;
      
        while( _curr->next != NULL){
        	_curr = _curr->next;
        }
      	_curr->next = singleTravelStorage;
       	printf("\nNew travel was added to your list of travells!\n");
    }
}

int getCurrentUserTravels(char* touristName, Travel* allTripsHead,
								Travel* currentTouristHead){
	Travel* curr;
	curr = allTripsHead;
	while(curr->next != NULL){
		if(strcmp(curr->touristName,touristName) == 0){
			addTravel(currentTouristHead,curr);
		}
		curr = curr->next;
	}
	if(strcmp(curr->touristName,touristName) == 0){
			addTravel(currentTouristHead,curr);
	}
	
	return 1;
}

int loadAllTravelsFromFile(Travel* allTripsHead,FILE *fp){
    Travel *singleTravel;
    Travel temp;
     
    // Open person.dat for reading
    fp = fopen ("Travels.dat", "r");

    if (fp == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    
    printf("Loading all trips from the file! \n");
    // read file contents till end of file
    while(fread(&temp, sizeof(Travel), 1, fp)){
		singleTravel = malloc(sizeof(Travel));
		*singleTravel = temp;
    	addTravel(allTripsHead, singleTravel);
    }
   	
   	fclose(fp);    	
	return 1;
}

int saveTravelsToFile(Travel* allTripsHead ,FILE *fp){

	Travel * curr;
	curr = allTripsHead;
    // open file for writing
    // when file is opened with mode "w" the content is 
    // erased and the file is threated as empty file 

    fp = fopen ("person.dat", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "\nError opend file\n");
        exit (1);
    }
    while(curr->next != NULL){
    	// write struct to file
    	fwrite(curr, sizeof(Travel), 1, fp);
    	if(fwrite == 0) {
    		printf("Error writing into the file! ");
    	}
    	curr = curr->next;
    }
     
    if(fwrite != 0) 
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");

	return 1;
}

void getTravelsByStOrEndDate(Travel* currentTouristHead ,
					char* dateToCompare,bool isStartDate){
	Travel * curr;
	curr = currentTouristHead;


	//no need from touristName check , cose all
	//travels are for the current tourist 
	while(curr->next != NULL){
		if(isStartDate){
			if(0 == strcmp(curr->beginning.date,dateToCompare)){
				printTravel(curr);
				curr = curr->next;
			}
		}else{
			if(0 == strcmp(curr->destination.date,dateToCompare)){
				printTravel(curr);
				curr = curr->next;
			}
		}
    }
   		if(isStartDate){
			if(0 == strcmp(curr->beginning.date,dateToCompare)){
				printTravel(curr);
				curr = curr->next;
			}
		}else{
			if(0 == strcmp(curr->destination.date,dateToCompare)){
				printTravel(curr);
				curr = curr->next;
			}
		}
}

double deg2rad(double degrees){
	return (degrees) * pi / 180.0;
}

double rad2deg(double radians){
	return (radians) * 180.0 / pi ;
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