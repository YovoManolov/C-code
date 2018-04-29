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
    printf("\nIf you want to clear the screen press Y !");
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

int addNewTrip(int sock,char* server_message){
    char place_name[50],date[12];
    double lon,lat,averageSpeed;

    //------------------------------------------
    //BEGINING
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    /*scanf("%lf",&lon);*/
    lon = 23.319941;

    //signal for writen input;
    if(send(sock ,&lon , sizeof(double) , 0) < 0)
    {
        puts("Sending beg longitude failed");
        return 1;
    }
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    /*scanf("%lf",&lat);*/
    lat = 42.698334;
    //signal for writen input;
    if(send(sock ,&lat , sizeof(double) , 0) < 0)
    {
       puts("Sending beg latitude failed");
       return 1;
    }
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    /*scanf("%s",place_name);*/
    strcpy(place_name,"sofia");
    //signal for writen input;
    if(send(sock , place_name , strlen(place_name) , 0) < 0)
    {
       puts("Sending beg starting position name failed");
       return 1;
    }
    memset(place_name, 0, 50);
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    /*scanf("%s",date);*/
    strcpy(date,"20/04/2018");

    //signal for writen input;
    if(send(sock ,date , strlen(date) , 0) < 0)
    {
       puts("Sending beg starting position date failed");
       return 1;
    }
    memset(date, 0, 12);
    //------------------------------------------
    //DESTINATION
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    /*scanf("%lf",&lon);*/
    lon = 27.910543;
    //signal for writen input;
    if(send(sock , &lon , sizeof(double) , 0) < 0)
    {
        puts("Sending destination longitude failed");
        return 1;
    }
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    /*scanf("%lf",&lat);*/
    lat = 43.204666;
    //signal for writen input;
    if(send(sock ,&lat , sizeof(double) , 0) < 0)
    {
        puts("Sending destination latitude failed");
        return 1;
    }
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    /*scanf("%s",place_name);*/
    strcpy(place_name,"varna");
    //signal for writen input;
    if(send(sock ,place_name, strlen(place_name) , 0) < 0)
    {
       puts("Sending destination position name failed!\n");
       return 1;
    }
    //------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    /*scanf("%s",date);*/
    strcpy(date,"22/04/2018");
    //signal for writen input;
    if(send(sock ,date , strlen(date) , 0) < 0)
    {
       puts("Sending arrival date failed! ");
       return 1;
    }
    //-------------------------------------------
    readMessageFromServer(sock,server_message,sizeof(server_message));
    /*scanf("%lf", &averageSpeed);*/
    averageSpeed = 300;
    //signal for writen input;
    if(send(sock ,&averageSpeed , sizeof(double) , 0) < 0)
    {
       puts("Sending avararage speed in km/h failed!\n");
       return 1;
    }

    readMessageFromServer(sock,server_message,sizeof(server_message));

 }

int main(int argc , char *argv[])
{
    int sock,menu_choice;
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
                if(1 == printAllMyTravels(sock,allMyTravelsHead)){
                    printf("Something went wrong!");
                    return 1;
                }
                break;
            case 2:
                if(1 == addNewTrip(sock,server_message)){
                    return 1;
                }
                break;
            case 3:
                 if(findTop_S_Distances(sock, server_message) != 0){
                     printf("\nThere was a problem with filtering your trips \n");
                 }
                break;
            case 4:
                  if(findTop_L_Distances(sock, server_message) != 0){
                         printf("\nThere was a problem with filtering your trips \n");
                  }
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

int printAllMyTravels(int sock,Travel* allMyTravelsHead){

    int i,numberOfTravelsToPrint;
    if(recv(sock ,&numberOfTravelsToPrint ,sizeof(int), 0) < 0){
        puts("recv failed");
    }else{
        printf("\n %d travels to be printed ! \n",numberOfTravelsToPrint);
    }
    //Single travel used as temp node to
    //iterate over the list of travels;
    printTravelsList(sock,numberOfTravelsToPrint);

    return 0;
}

void printTravelsList(int sock,int numberOfTravelsToPrint){
    Travel* curr;
    int read_size;
    curr = malloc(sizeof(Travel));

    for(int i = 0;i< numberOfTravelsToPrint ;i ++){
        //=============================
        //STARTING POSITION
        //=============================
        if((read_size = recv(sock,&curr->beginning.Lon,sizeof(double),0)) < 0){
           perror("Error reading start pos Longitude!:  ");
        }
        if((read_size = recv(sock,&curr->beginning.Lat,sizeof(double),0)) < 0){
        perror("Error reading start pos Latitude!:  ");
        }
        if((read_size = recv(sock,curr->beginning.name,50,0)) < 0){
            perror("Error reading start pos name!:  ");
        }
        if((read_size = recv(sock,curr->beginning.date,12,0)) < 0){
            perror("Error reading departure date!:  ");
        }
        //=============================
        //DESTINATION
        //=============================
        if((read_size = recv(sock,&curr->destination.Lon,sizeof(double),0)) < 0){
           perror("Error reading destination Longitude!:  ");
        }
        if((read_size = recv(sock,&curr->destination.Lat,sizeof(double),0)) < 0){
        perror("Error reading destination Latitude!:  ");
        }
        if((read_size = recv(sock,curr->destination.name,50,0)) < 0){
            perror("Error reading destination name!:  ");
        }
        if((read_size = recv(sock,curr->destination.date,12,0)) < 0){
            perror("Error reading arrival date!:  ");
        }

        //=============================
        //=============================
        if((read_size = recv(sock,&(curr->averageSpeed),sizeof(double),0)) < 0){
             perror("Error reading average speed!:  ");
        }
        if((read_size = recv(sock,&(curr->distance),sizeof(double),0)) < 0){
             perror("Error reading average speed!:  ");
        }
        if((read_size = recv(sock,&(curr->averageDuration),sizeof(double),0)) < 0){
             perror("Error reading average speed!:  ");
        }

        printf("\n---------------Next Travel---------------\n");
        curr = curr->next;
        printTravel(curr);
    }
    free(curr);
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

int findTop_S_Distances(int sock,char* server_message){
    int numberOfTravelsToBeReceived;
    int countOfMyPastTrips;


    readMessageFromServer(sock,server_message,sizeof(server_message));
    scanf("%d", &numberOfTravelsToBeReceived);

    if(numberOfTravelsToBeReceived > countOfMyPastTrips){
        printf("Please enter number which is less or equal to the number of your past travels\n");
        scanf("%d", &numberOfTravelsToBeReceived);
    }

    if(send(sock ,&numberOfTravelsToBeReceived, sizeof(int) , 0) < 0)
    {
        puts("Sending number of shortest trips to be returned failed!\n");
        return 1;
    }

    printTravelsList(sock,numberOfTravelsToBeReceived);

    return 0;
 }

int findTop_L_Distances(int sock,char* server_message){
    int numberOfTravelsToBeReceived;
    int countOfMyPastTrips;

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

     printTravelsList(sock,numberOfTravelsToBeReceived);

    return  0;
 }

