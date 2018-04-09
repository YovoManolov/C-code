/*
 * server.h
 *
 *  Created on: Apr 9, 2018
 *      Author: yovo
 */

#ifndef SERVER_H_
#define SERVER_H_


#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h>
//for distance calcuation
#include <math.h>
#define PI 3.14159265358979323846


typedef struct place {
   double Lon;
   double Lat;
   char name[50];
   char date[12]; //dd-mm-yyyy
} Place ;

typedef struct Travel Travel;
struct Travel {
   Place beginning;
   Place destination;
   double distance;
   Travel* next;
};

typedef struct tourist {
   char name[20];
   /*take from xml increment save to xml
   id of last added travel
   starting from 1 to n*/
   int countOfTravels;
   Travel* headNode;
} Tourist;


void *connection_handler(void *);
void loadTravelInfo(void* socket_desc,Travel* t);
double deg2rad(double);
double rad2deg(double);
/*:: unit = the unit you desire for results                                  :*/
/*::           where: 'M' is statute miles (default)                         :*/
/*::                  'K' is kilometers                                      :*/
/*::                  'N' is nautical miles                                  :*/
double distance(double lat1, double lon1, double lat2, double lon2, char unit);

#endif /* SERVER_H_ */