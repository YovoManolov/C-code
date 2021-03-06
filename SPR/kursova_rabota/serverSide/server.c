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

	int lastIdInt = 0 ;//to keepTrackOfCurrentUserTravelId's
	//to keepTrackOfCurrentUserTravelId's
	//used to make statistics requests from client.
	int signalReceived; // signal from client

	char messageToClient[500],touristName[50];
	FILE* fp = NULL;
	Travel* allTravelsHead = NULL;
	Travel* currentTouristHead = NULL;
	Travel* singleTravelStorage = NULL;
	Travel* userSearchListPointer = NULL;

	strcpy(messageToClient ,"Hi client! I am your connection handler");
	write(sock, messageToClient, 500);
	memset(messageToClient, 0, 500);

	strcpy(messageToClient ,"Please enter your name: ");
	write(sock, messageToClient, 500);
	memset(messageToClient, 0, 500);

	if((read_size = recv(sock,touristName,50,0)) < 0){
		perror("Error reading current tourist name !:  ");
	}else{
		printf("Tourist with name %s has connected! ",touristName);
	}

	// =================================================
	// =================================================
	// Load all travels from file
	// Extract only those for current Traveller
	// =================================================
	// =================================================

	//TO DO synchronize file usage between threads
	if(loadAllTravelsFromFile(&allTravelsHead,fp) == 1){
		printf("Loading trips from file has failed! \n");
		//in case of not created file !
		numberOfTrips = 0;
		write(sock,&numberOfTrips,sizeof(int));
	}else{
		getCurrentUserTravels(touristName,allTravelsHead,&currentTouristHead);

		numberOfTrips = getListSize(currentTouristHead);
		if(numberOfTrips == 0){
			printf("List of user's travels is empty requests cannot be fulfilled!");
		}

		write(sock,&numberOfTrips,sizeof(int));
		//initialize the last id in the list of trips with the number of all
		//the travels for this user token from the file.
		lastIdInt = numberOfTrips;

	}

	// =================================================

	//recv returns -1 on error and number of bites received on success
	while((read_size = recv(sock,&menu_choice,sizeof(int),0)) != -1){
		
		switch(menu_choice){
			case 1:
				printTravelsFromHeadNode(socket_desc,currentTouristHead);
				break;
			case 2: 
				singleTravelStorage = malloc(sizeof(Travel));
				receiveNewTravelInfo(socket_desc, singleTravelStorage, touristName,&lastIdInt);
				addTravel(&currentTouristHead,singleTravelStorage);
				strcpy(messageToClient,"\nNew travel was added to your list of travells!\n");
		      	write(sock, messageToClient,strlen(messageToClient));

				break;
			case 3:
				findTravelByStartEndDate(socket_desc,currentTouristHead);
				break;
			case 4: 
				findTop_L_Distances(socket_desc,messageToClient,
							currentTouristHead,&userSearchListPointer);
				break;
			case 5:
				findTop_S_Distances(socket_desc,messageToClient,
							currentTouristHead,&userSearchListPointer);
				break;
			case 6:
				//delete current user travels from allTravelsStruct
				deleteCurrentUserTravels(touristName, &allTravelsHead);
				addCurrUsTravToAllTravels(&allTravelsHead ,currentTouristHead);
				saveTravelsToFile(socket_desc,allTravelsHead ,fp);
				writeMessageToClient(sock,"\nThank you for using our services!\n");
				if((read_size = recv(sock,&signalReceived,sizeof(int),0)) < 0){
					perror("Shut down message not received !:  ");
				}else{
					printf("Client disconnected");
					free(socket_desc);
					close(sock);
					pthread_exit(NULL);
					return;
				}
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
}

void findTop_S_Distances(void* socket_desc,char* messageToClient,Travel* currentTouristHead,Travel** userSearchListPointer){
	int sock = *(int*) socket_desc ;
	int read_size;
	int numberOfTravelsToSearchFor,currentUserTravelsCount;

	currentUserTravelsCount = getListSize(currentTouristHead);
	write(sock, &currentUserTravelsCount, sizeof(int));

	strcpy(messageToClient ,"Please enter number top longest travels to be returned : ");
	write(sock, messageToClient, 500);
	memset(messageToClient, 0, 500);
	if((read_size = recv(sock,&numberOfTravelsToSearchFor,sizeof(int),0)) < 0){
		perror("Number of trips was not received !:  ");
	}else{
		//2cond arg : bool topShortest
		//if false  : topLongest
		topWantedDistances(currentTouristHead,false,userSearchListPointer,numberOfTravelsToSearchFor);
		printTravelsFromHeadNode(socket_desc, *userSearchListPointer);
	}
}

void findTop_L_Distances(void* socket_desc,char* messageToClient,Travel* currentTouristHead,Travel** userSearchListPointer){
	int sock = *(int*) socket_desc ;
	int read_size;
	int numberOfTravelsToSearchFor,currentUserTravelsCount;

	currentUserTravelsCount = getListSize(currentTouristHead);
	write(sock,&currentUserTravelsCount, sizeof(int));

	strcpy(messageToClient ,"Please enter number of top shortest trips to be returned : ");
	write(sock, messageToClient, 500);
	memset(messageToClient, 0, 500);
	if((read_size = recv(sock,&numberOfTravelsToSearchFor,sizeof(int),0)) < 0){
		perror("Number of trips was not received !:  ");
	}else{
		//2cond arg : bool topShortest
		//if false  : topLongest
		topWantedDistances(currentTouristHead,true,userSearchListPointer,numberOfTravelsToSearchFor);
		printTravelsFromHeadNode(socket_desc,*userSearchListPointer);
	}
}

int getListSize(Travel* head){
	int listSize;
	Travel* curr;
	curr = head;
	if(curr){
		listSize = 1;
	}else{
		listSize = 0;
		return listSize;
	}
	while(curr->next){
		listSize += 1;
		curr = curr->next;
	}
	return listSize;
}

//stOrEndDate - true->search by start date
//stOrEndDate - false->search by end date
void findTravelByStartEndDate(void* socket_desc,Travel* currentTouristHead){
	int sock = *(int*) socket_desc ;
	Travel *curr;
	char dateToSearch[12];
	int dateTypeChoice,read_size;
	bool isTravelFound = false;

	if((read_size = recv(sock,&dateTypeChoice,sizeof(int),0)) <= 0){
        perror("Error receiving date type choice !: \n");
    }else {
    	writeMessageToClient(sock,"Searching date type is received\n");
    }

    if((read_size = recv(sock,dateToSearch,12,0)) <= 0){
        perror("Error receiving date to search with !: \n");
    }else {
    	writeMessageToClient(sock,"Date is received !\n");
    }

    //the idea is there cannot be more than 1 travels with the same
    //start or end date for the same traveller/client
	curr = currentTouristHead;
    if(dateTypeChoice == 1){
		while(curr){
			if(strcmp(curr->beginning.date,dateToSearch) == 0){
					isTravelFound = true;
					write(sock,&isTravelFound,sizeof(bool));
					sendSigleTravelInfoToClient(socket_desc,curr);
					break;
			}else{
				curr = curr->next;
			}
		}
	}else if(dateTypeChoice == 2){
		while(curr){
			if(strcmp(curr->destination.date,dateToSearch) == 0){
				isTravelFound = true;
				write(sock,&isTravelFound,sizeof(bool));
				sendSigleTravelInfoToClient(socket_desc,curr);
				break;
			}else{
				curr = curr->next;
			}
		}
	}else{
		printf("\nDate type choice is invalid!\n");
	}

	if(isTravelFound){
		if(dateTypeChoice == 1){
			printf("\n Successfully found travel by start date!\n");
		}else if(dateTypeChoice == 2){
			printf("\n Successfully found travel by end date!\n");
		}
	}
	write(sock,&isTravelFound,sizeof(bool));
}

//if topShortest is false top longest are filtered
void topWantedDistances(Travel* currentTouristHead,bool topShortest,
					Travel** userSearchListPointer,int countOfTripsToReturn){
	Travel *curr;

	int listSize = getListSize(currentTouristHead);
	if(listSize == 0){
		printf("List of travels is empty request cannot be fulfilled!");
	}

	int distanceArr [listSize][2]; //first column id sec column distance;
	int swap [1][2];
	int i,j;
	int *IDsOfWantedTrips;

	i = 0;
	curr = currentTouristHead;
	while(curr){
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
		           swap[0][0] = distanceArr[i][0];
		           swap[0][1] = distanceArr[i][1];

		           distanceArr[i][0] = distanceArr[j][0];
		           distanceArr[i][1] = distanceArr[j][1];

		           distanceArr[j][0] = swap[0][0];
		           distanceArr[j][1] = swap[0][1];
		       }
		    }
		 }

	}else{
		// array sorting in descending order
		for(i=0; i < listSize; i++) {
		    for (j = i+1; j < listSize; j++) {
		       if(distanceArr[i][1] < distanceArr[j][1]){
		    	   swap[0][0] = distanceArr[i][0];
		    	   swap[0][1] = distanceArr[i][1];

		    	  distanceArr[i][0] = distanceArr[j][0];
		    	  distanceArr[i][1] = distanceArr[j][1];

		    	  distanceArr[j][0] = swap[0][0];
		    	  distanceArr[j][1] = swap[0][1];
		       }
		    }
		}
	}

	IDsOfWantedTrips = malloc(countOfTripsToReturn * sizeof(int));
	for(i = 0; i < countOfTripsToReturn ;i++){
		//we fill the array with the first "countOfTripsToReturn"
		//values from the sorted 2D array
		*(IDsOfWantedTrips + i) = distanceArr[i][0];
	}

	filteredTravelsById(userSearchListPointer,
				currentTouristHead,IDsOfWantedTrips,countOfTripsToReturn);

	free(IDsOfWantedTrips);
}

void filteredTravelsById(Travel** userSearchListPointer,Travel* currentTouristHead,
								int* IDsOfWantedTrips,int countOfTripsToReturn){
	Travel* curr ;
	Travel* temp;

	for(int i=0 ;i < countOfTripsToReturn ;i++){
		curr = currentTouristHead;
		while(curr){
			if((*(IDsOfWantedTrips + i)) == curr->id){
				temp = malloc(sizeof(Travel));
				temp = curr;
				temp->next = NULL;
			  	addTravel(userSearchListPointer,temp);
			  	break;
			}
			curr = curr->next;
		}
	}

}

void receiveNewTravelInfo(void* socket_desc,Travel* receivedTravel
			,char* touristName,int* lastIdInt){

	int sock = *(int*) socket_desc ;
	int singal = 1;
	int read_size;

	char place_name[50],date[12];
	char* ascForInput;
    double Lon,Lat,averageSpeed;

	receivedTravel->id = (*lastIdInt) += 1;

	if(strlen(touristName) > 0 ){
		strcpy(receivedTravel->touristName, touristName);
	}
	//=============================
	//STARTING POSITION
	//=============================
	/*
	ascForInput = "Please enter Longitude of starting position:\0";
	write(sock, ascForInput,strlen(ascForInput));
	*/
	writeMessageToClient(sock,"Please enter Longitude of starting position:\0");
	if((read_size = recv(sock,&Lon,sizeof(double),0)) < 0){
   	   perror("Error reading start pos Longitude!:  ");
    }else{
       receivedTravel->beginning.Lon = Lon;
    }

    write(sock,&singal,sizeof(int)); //for synchronization;

	/*ascForInput = "Please enter Latitude of starting position:\0";
	write(sock, ascForInput,strlen(ascForInput));*/
	writeMessageToClient(sock,"Please enter Latitude of starting position:\0");
	if((read_size = recv(sock,&Lat,sizeof(double),0)) < 0){
	    perror("Error reading start pos Latitude!:  ");
	}else{
	    receivedTravel->beginning.Lat = Lat;
	}

	write(sock,&singal,sizeof(int)); //for synchronization;

	ascForInput = "Please enter name of starting position:\0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,place_name,50,0)) < 0){
    	perror("Error reading start pos name!:  ");
  	}else{
    	strcpy(receivedTravel->beginning.name,place_name);
  	}
  	memset(place_name, 0, 50);

  	write(sock,&singal,sizeof(int)); //for synchronization;

	ascForInput = "Please enter date of departure like dd/mm/yyyy:\0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,date,12,0)) < 0){
    	perror("Error reading departure date!:  ");
 	}else{
    	strcpy(receivedTravel->beginning.date, date);
  	}
  	memset(place_name, 0, 12);

  	write(sock,&singal,sizeof(int)); //for synchronization;
	//=============================
	//DESTINATION
	//=============================
	ascForInput = "Please enter Longitude of destination:\0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,&Lon,sizeof(double),0)) < 0){
    	perror("Error reading destination Longitude!:  ");
    }else{
       receivedTravel->destination.Lon = Lon;
    }

    write(sock,&singal,sizeof(int)); //for synchronization;
 	
	ascForInput = "Please enter Latitude of destination:\0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,&Lat,sizeof(double),0)) < 0){
   		perror("Error reading destination latitude failed!:  ");
  	}else{
    	receivedTravel->destination.Lat = Lat ;
  	}
  	memset(place_name, 0, 50);

  	write(sock,&singal,sizeof(int)); //for synchronization;

	ascForInput = "Please enter name of destination position:\0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,place_name,50,0)) < 0){
    	perror("Error reading destination pos name!:  ");
    }else{
    	strcpy(receivedTravel->destination.name,place_name);
    }
  	memset(place_name, 0, 50);

  	write(sock,&singal,sizeof(int)); //for synchronization;

	ascForInput = "Please enter date of arrival like dd/mm/yyyy:\0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,date,12,0)) < 0){
    	perror("Error reading arrival date!:  ");
    }else{
    	strcpy(receivedTravel->destination.date, date);
 	}
    memset(date, 0, 12);

    write(sock,&singal,sizeof(int)); //for synchronization;

	ascForInput = "Please enter average speed in km/h: \0";
	write(sock, ascForInput,strlen(ascForInput));
	if((read_size = recv(sock,&averageSpeed,sizeof(double),0)) < 0){
   		 perror("Error reading average speed!:  ");
  	}else{
    	receivedTravel->averageSpeed = averageSpeed ;
  	}

	receivedTravel->distance = distance(receivedTravel->beginning.Lon,
				receivedTravel->beginning.Lat,receivedTravel->destination.Lon,
				receivedTravel->destination.Lat,'K');
		//always adding the wast node
	receivedTravel->averageDuration = (receivedTravel->distance / receivedTravel->averageSpeed);
	receivedTravel->next = NULL;
}


void sendSigleTravelInfoToClient(void* socket_desc,Travel* travelToSend){
	int sock = *(int*) socket_desc ;
	int isDataReceived,read_size;

	write(sock, travelToSend->touristName,sizeof(50));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client: touristName\n");
    }

	//=============================
	//STARTING POSITION
    //=============================
	write(sock, &(travelToSend->beginning.Lon),sizeof(double));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client: beginning.Lon\n");
    }
	write(sock, &(travelToSend->beginning.Lat),sizeof(double));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client: beginning.Lat\n");
    }
	write(sock, travelToSend->beginning.name,
							strlen(travelToSend->beginning.name));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client: beginning.name\n");
    }
	write(sock, travelToSend->beginning.date,
							strlen(travelToSend->beginning.date));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client: beginning.date\n");
    }
	//=============================
	//DESTINATION
    //=============================
	write(sock, &(travelToSend->destination.Lon),sizeof(double));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client: destination.Lon\n");
    }
	write(sock, &(travelToSend->destination.Lat),sizeof(double));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client: destination.Lat\n");
    }
	write(sock, travelToSend->destination.name,
							strlen(travelToSend->destination.name));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client: destination.name\n");
    }
	write(sock, travelToSend->beginning.date,
							strlen(travelToSend->destination.date));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client: destination.date\n");
    }
	//=============================
    //=============================
	write(sock, &(travelToSend->averageSpeed),sizeof(double));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client:averageSpeed\n");
    }
	write(sock, &(travelToSend->distance),sizeof(double));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client:distance\n");
    }
	write(sock, &(travelToSend->averageDuration),sizeof(double));
	if((read_size = recv(sock,&isDataReceived,sizeof(int),0)) <= 0){
        perror("Error receiving signal for recieved data!:  ");
    }else if(isDataReceived == 0) {
    	printf("\nData not received from client:averageDuration\n");
    }

	printf("\nSingle travel sended to client!\n\n");
}

void printTravelsFromHeadNode(void* socket_desc,Travel* currentTouristHead){
	int sock = *(int*) socket_desc;
	int listSize;
	Travel * curr;
	curr = currentTouristHead;

	listSize = getListSize(curr);
	if(listSize == 0){
		printf("List of travels is empty request cannot be fulfilled!");
		write(sock,&listSize,sizeof(int));
		return;
	}

	//no need from touristName check , cose all
	//travels are for the current tourist
	write(sock,&listSize,sizeof(int));
	if(curr){
    	sendSigleTravelInfoToClient(socket_desc,curr);
    }
	while(curr->next){
		curr = curr->next;
		sendSigleTravelInfoToClient(socket_desc,curr);
    }
}

int addTravel(Travel** _head,Travel* singleTravelStorage){
	Travel *_curr;

	if(!(*_head)){
         (*_head) = singleTravelStorage;
         return 0;
    }else{
        _curr = (*_head);

        while(_curr->next){
        	_curr = _curr->next;
        }
      	_curr->next = singleTravelStorage;
      	return 0;
    }
}

void addCurrUsTravToAllTravels(Travel** allTravelsHead ,Travel* currentTouristHead){

	if(!currentTouristHead){
    	printf("Current tourist list is empty. Something went wrong!");
    }else{
    	if(!(*allTravelsHead)){
    		(*allTravelsHead) = currentTouristHead;
    	}else{
    		while((*allTravelsHead)->next){
    			(*allTravelsHead) = (*allTravelsHead)->next;
    		}
    		(*allTravelsHead)->next = currentTouristHead;
    	}
		printf("Updated travels of current user added to allTravelsHead :) !");
    }

	return;
}


// deletes old travels from allTravelsHead
void deleteCurrentUserTravels(char* touristName, Travel** allTravelsHead){
	Travel* temp = *allTravelsHead;
	Travel* prev = *allTravelsHead;

	int deletedTravels = 0;

	// If head node itself holds the key to be deleted
    while (temp != NULL && strcmp(temp->touristName,touristName) == 0 )
    {
        *allTravelsHead = temp->next;   // Changed head
        free(temp);               		// free old head
        deletedTravels += 1;
        temp = *allTravelsHead;
        prev = *allTravelsHead;
    }

    while(1){
    	// Search for the key to be deleted, keep track of the
	    // previous node as we need to change 'prev->next'
	    while (temp != NULL && strcmp(temp->touristName,touristName) != 0)
	    {
	        prev = temp;
		    temp = temp->next;
	    }
	 	// If key was not present in linked list
	    if (temp == NULL){
	    	break;
	    } else{
		    prev->next = temp->next;
			free(temp);
			deletedTravels += 1 ;
			temp = prev->next;
	    }
    }
	//like logs in the server side;
    printf("Number of travels delted from file : %d ", deletedTravels);
	return ;
}

void getCurrentUserTravels(char* touristName, Travel* allTravelsHead,
								Travel** currentTouristHead){
	Travel* allTravelsIterator;
	Travel* tempNode;
	allTravelsIterator = allTravelsHead;

	if(allTravelsIterator->next){
		while(allTravelsIterator->next){
			if(strcmp(allTravelsIterator->touristName,touristName) == 0){
				tempNode = malloc(sizeof(Travel));
				*tempNode = *allTravelsIterator;
				tempNode->next = NULL;
				//will nead new malloc
				if(addTravel(currentTouristHead,tempNode) == 0){
					printf("\nTravel added successfully !\n");
				}else{
					printf("\nAdding travel failed !\n");
				}
			}
			allTravelsIterator = allTravelsIterator->next;
		}
	}
	if(allTravelsIterator){
		if(strcmp(allTravelsIterator->touristName,touristName) == 0){
			tempNode = malloc(sizeof(Travel));
			*tempNode = *allTravelsIterator;
			tempNode->next = NULL;
			//will nead new malloc
			if(addTravel(currentTouristHead,tempNode) == 0){
				printf("\nTravel added successfully !\n");
			}else{
				printf("\nAdding travel failed !\n");
			}
	    }
	}
}

int loadAllTravelsFromFile(Travel** allTravelsHead,FILE *fp){
    Travel *singleTravel;
    bool smthRdScs;  //somthing readed successfully ?
    singleTravel = malloc(sizeof(Travel));
    // Open Travels.dat for reading
    fp = fopen ("Travels.dat", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "\nFile was not successfully opened \n");
        return 1;
    }
    //count the number of trips in the file to allocate memmory
    int countOfAllTravels = 0;
    while(1 == fread(singleTravel,sizeof(Travel), 1, fp)){
    	countOfAllTravels +=1;
    }

    rewind(fp);

    printf("Loading all trips from the file! \n");
    // read file contents till end of file
    singleTravel = malloc(sizeof(Travel));
    while(fread(singleTravel, sizeof(Travel), 1, fp) == 1){
    	singleTravel->next = NULL;
    	if(addTravel(allTravelsHead,singleTravel) == 0){
    			printf("\nTravel added from file successfully !\n");
    			smthRdScs = true;
    	    	singleTravel = malloc(sizeof(Travel));
    	}else{
    			printf("\nAdding travel from file failed !\n");
    	}
    }
   	fclose(fp);

   	if(smthRdScs){
   		return  0;
   	}else{
   		return 1;
   	}
}

int saveTravelsToFile(void* socket_desc,Travel* allTravelsHead ,FILE *fp){

	int sock = *(int*) socket_desc ;
	int isMessageReceived,read_size;
	bool successfullyWritenData;
	Travel* curr;
	curr = allTravelsHead;
    // open file for writing
    // when file is opened with mode "w" the content is
    // erased and the file is threated as empty file

    fp = fopen ("Travels.dat", "w");
    if (!fp)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    if(!allTravelsHead){
    	printf("All travels list is empty. Something went wrong!");
    	successfullyWritenData = false;
    }

   	while(curr){
    	// write struct to file
    	if((fwrite(curr, sizeof(Travel), 1, fp)) == 1){
    		successfullyWritenData = true;
    	}else{
    		successfullyWritenData = false;
    		break;
    	}
    	curr = curr->next;
    }

   	fclose(fp);
   	if(successfullyWritenData){
   		writeMessageToClient(sock,"Your trips were successfully saved");
   	}else{
   		writeMessageToClient(sock,"Your trips were not saved successfully!");
   	}

	if((read_size = recv(sock,&isMessageReceived,sizeof(int),0)) <= 0){
            perror("Error receiving signal for recieved data!:  ");
    }else if(isMessageReceived == 0) {
    	printf("\nData not received from client: beginning.name\n");
    }

	return 0;
}

void getTravelsByStOrEndDate(void* socket_desc,Travel* currentTouristHead ,
					char* dateToCompare,bool isStartDate){
	int sock = *(int*) socket_desc;
	Travel * curr;
	curr = currentTouristHead;

	//no need from touristName check , cose all
	//travels are for the current tourist
	if(isStartDate){
		while(curr->next){
			if(0 == strcmp(curr->beginning.date,dateToCompare)){
				write(sock,curr,sizeof(Travel));
				curr = curr->next;
			}
		}
    }
	else{
		while(curr->next){
			if(0 == strcmp(curr->destination.date,dateToCompare)){
				write(sock,curr,sizeof(Travel));
				curr = curr->next;
			}
		}
	}
}
void writeMessageToClient(int sock,char* messageToClient){
	write(sock, messageToClient, strlen(messageToClient));
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
