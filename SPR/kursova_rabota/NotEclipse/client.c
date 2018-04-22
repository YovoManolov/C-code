/*
    C ECHO client example using sockets
*/
#include "client.h"

void printMenu(){
	printf("Please make your choice from the following menu! \n");
   	printf("\n\n---------MENU---------");
   	printf("\n1.Всички мои пътувания");
   	printf("\n2.Добави ново пътуване");
   	printf("\n3.Намери пътуване по дата на тръгване");
   	printf("\n4.Изведи 10-те най-дълги пътувания");
   	printf("\n5.Изведи 10-те най-къси пътувания");
   	printf("\n6.Изход\n\n");
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
	Travel* newTravel;
	int loadedDataSignal = 1;
	newTravel = malloc(sizeof(Travel));
    //------------------------------------------
    //BEGINING
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%lf",&(newTravel->beginning.Lon));
    //signal for writen input;
    write(sock,&loadedDataSignal,sizeof(int));
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%lf",&(newTravel->beginning.Lat));
    //signal for writen input;
    write(sock,&loadedDataSignal,sizeof(int));
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%s",newTravel->beginning.name);
    //signal for writen input;
    write(sock,&loadedDataSignal,sizeof(int));
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%s",newTravel->beginning.date);
    //signal for writen input;
    write(sock,&loadedDataSignal,sizeof(int));
    //------------------------------------------
    //DESTINATION
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%lf",&(newTravel->destination.Lon));
    //signal for writen input;
    write(sock,&loadedDataSignal,sizeof(int));
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%lf",&(newTravel->destination.Lon));
    //signal for writen input;
    write(sock,&loadedDataSignal,sizeof(int));
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%s",newTravel->destination.name);
    //signal for writen input;
    write(sock,&loadedDataSignal,sizeof(int));
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%s",newTravel->destination.date);
    //signal for writen input;
    write(sock,&loadedDataSignal,sizeof(int));
    //-------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%lf",&(newTravel->averageSpeed));
    //signal for writen input;
    write(sock,&loadedDataSignal,sizeof(int));

    if(send(sock ,newTravel ,sizeof(Travel) , 0) < 0)
    {
        puts("Sending new Travel failed!\n");
        return 1;
    }
}

int main(int argc , char *argv[])
{
    int sock,menu_choice,f_returnVal;
    int countOfPrintedTrips;
    struct sockaddr_in server;
    char server_message[500],touristName[50];
	Travel *allMyTravelsHead;



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
    //greeting
    readMessageFromServer(sock,server_message,sizeof(server_message));
    //please enter your name
    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%s",touristName);
    if(send(sock ,touristName,strlen(touristName), 0) < 0)
    {
        puts("Your name was not sended!");
        return 1;
    }else{
	    if(recv(sock , &countOfPrintedTrips ,sizeof(int), 0) < 0){
			 puts("recv failed");
			 return 1;
		}else{
			if(countOfPrintedTrips != 0 ){
				printf(" %d trips wore taken from file!\n" , countOfPrintedTrips);
			 	allMyTravelsHead = malloc(countOfPrintedTrips *sizeof(Travel));
			}
			else{
				//count of trips is euqal to 0;
				printf("You have no travels writen into the system!");
			}
		}
    }

    //keep communicating with server
    while(1)
    {
    	clearScreen();
    	printMenu();
    	scanf("%d",&menu_choice);
        if(send(sock ,&menu_choice , sizeof(int) , 0) < 0)
        {
           puts("Menu choice sending failed!");
           return 1;
        }

        switch(menu_choice){
        	case 1:
        		if(1 == printAllMyTravels(sock,allMyTravelsHead,countOfPrintedTrips)){
        			printf("Something went wrong!");
					return 1;
				}
				break;
			case 2:
				if(1 == addNewTrip(sock,server_message,)){
					return 1;
				}
				break;
			case 3: 
				  findTop_S_Distances(sock, server_message, countOfPrintedTrips);
				break;
			case 4: 
				  findTop_L_Distances(sock, server_message, countOfPrintedTrips);
				break;
			case 5:
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("You selected invalid option, please try again!");
				break;
		}

    }
     
    close(sock);
    return 0;
}

int printAllMyTravels(int sock,Travel* allMyTravelsHead,int countOfPrintedTrips){

	Travel  *singleTravel;
	int i;
	singleTravel = malloc(sizeof(Travel));

    for(i = 0 ;i < countOfPrintedTrips ; i++){
    	if(recv(sock ,singleTravel ,sizeof(Travel), 0) < 0){
			 puts("recv failed");
		}else{
			 addTravel(allMyTravelsHead,singleTravel);
		}

	}
	//Single travel used as temp node to
	//iterate over the list of travels;
	printTravelsList(allMyTravelsHead);

    return 0;
}

void printTravelsList(Travel* head){

	Travel* curr = head;
	while(curr->next != NULL){
		printTravel(curr);
		printf("\n---------------Next Travel---------------\n");
    	curr = curr->next;
    }
    printTravel(curr);
}

 void printTravel(Travel *t){
    //!!!!!!!!!!!!!!!!!!!!!!
    //TO BE SENDED TO CLIENT
    //!!!!!!!!!!!!!!!!!!!!!!
    printf("---------------------------------\n");
    printf("Traveller : %s \n",t->touristName);
    printf("Beginning longitude %lf \n",t->beginning.Lon);
    printf("Beginning latitude %lf \n", t->beginning.Lat);
    printf("Beginning name %s \n", t->beginning.name);
    printf("Beginning date %s \n", t->beginning.date);
    printf("Destination longitude %lf \n", t->destination.Lon);
    printf("Destination latitude %lf \n", t->destination.Lat);
    printf("Destination name %s \n", t->destination.name);
    printf("Destination date %s \n", t->destination.date);
    printf("The distance of your trip is :%lf",t->distance);
    printf("---------------------------------\n");
}

int findTop_S_Distances(int sock,char* server_message,int countOfMyPastTrips){
	int numberOfTravelsToBeReceived;
	Travel *topSLTravels;
	Travel* singleTravelStorage;
	singleTravelStorage = malloc(sizeof(Travel));

 	readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%d", &numberOfTravelsToBeReceived);

    if(numberOfTravelsToBeReceived > countOfMyPastTrips){
    	printf("Please enter number which is less or equal to the number of your past travels\n");
    	scanf("%d", &numberOfTravelsToBeReceived);
    }

    if(send(sock ,&numberOfTravelsToBeReceived, sizeof(numberOfTravelsToBeReceived) , 0) < 0)
    {
        puts("Sending number of shortest trips to be returned failed!\n");
        return 1;
    }

	topSLTravels = malloc(sizeof(Travel)* numberOfTravelsToBeReceived);
    while(recv(sock ,singleTravelStorage,sizeof(Travel), 0) > 0){
		addTravel(topSLTravels,singleTravelStorage);
	}

	printTravelsList(topSLTravels);

	free(singleTravelStorage);
	free(topSLTravels);
 }

int findTop_L_Distances(int sock,char* server_message,int countOfMyPastTrips){
 	int numberOfTravelsToBeReceived;
	Travel *topSLTravels;
	Travel* singleTravelStorage;
	singleTravelStorage = malloc(sizeof(Travel));

 	readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%d", &numberOfTravelsToBeReceived);

    if(numberOfTravelsToBeReceived > countOfMyPastTrips){
    	printf("Please enter number which is less or equal to the number of your past travels\n");
    	scanf("%d", &numberOfTravelsToBeReceived);
    }

    if(send(sock , &numberOfTravelsToBeReceived, sizeof(numberOfTravelsToBeReceived) , 0) < 0)
    {
        puts("Sending number of longest trips to be returned failed!\n");
        return 1;
    }

	topSLTravels = malloc(sizeof(Travel)* numberOfTravelsToBeReceived);
    while(recv(sock ,singleTravelStorage,sizeof(Travel), 0) > 0){
		addTravel(topSLTravels,singleTravelStorage);
	}

	printTravelsList(topSLTravels);

	free(singleTravelStorage);
	free(topSLTravels);
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

