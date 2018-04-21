/*
 * client.h
 *
 *  Created on: Apr 9, 2018
 *      Author: yovo
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include<stdio.h> //printf
#include<stdlib.h>
#include<string.h>    //strlen
#include<unistd.h>
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr

typedef struct place {
   double Lon;
   double Lat;
   char name[50];
   char date[12]; //dd-mm-yyyy
} Place ;

typedef struct Travel Travel;
struct Travel {
   int id; 
   // ascending used only for 
   // single client statistics 
   //value in allTravelStructures
   //is formal and not used 
   char touristName[50];
   Place beginning;
   Place destination;
   double averageSpeed;
   double distance;
   double averageDuration;
   Travel* next;
};


void clearScreen();
void printMenu();
void readMessageFromServer(int sock,char* server_message, int sizeOfMessage);
int addNewTrip(int sock,char* server_message);
int findTop_L_Distances(int sock,char* server_message,int countOfPrintedTrips);
int findTop_S_Distances(int sock,char* server_message,int countOfPrintedTrips);
int printAllMyTravels(int sock,char* server_message,int size);
void printTravel(Travel *t);
void addTravel(Travel *_head,Travel* singleTravelStorage);

#endif /* CLIENT_H_ */
