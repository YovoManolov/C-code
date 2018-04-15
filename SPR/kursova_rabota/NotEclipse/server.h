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
#define pi 3.14159265358979323846


typedef struct place {
   double Lon;
   double Lat;
   char name[50];
   char date[12]; //dd-mm-yyyy
} Place ;

typedef struct Travel Travel;
struct Travel {
   char touristName[50];
   Place beginning;
   Place destination;
   double averageSpeed;
   double distance;
   double averageDuration;
   Travel* next;
};

/*typedef struct tourist {
   char name[20];
   int countOfTravels; 
   Travel* headNode;
} Tourist;
*/

void *connection_handler(void *);
int loadAllTravelsFromFile(Travel* allTripsHead,FILE *fp);
int saveTravelsToFile(Travel* head);
void getTravelsByStOrEndDate(Travel* currentTouristHead ,
               char* dateToCompare,boolean isStartDate)
void receiveNewTravelInfo(void* socket_desc,Travel* t,char* touristName);
void printTravel(Travel *t);
void addTravel(Travel *_head,Travel* singleTravelStorage);
int getCurrentUserTravels(char* touristName, Travel* allTripsHead,
                              Travel* currentTouristHead);

double deg2rad(double);
double rad2deg(double);
/*:: unit = the unit you desire for results                                  :*/
/*::           where: 'M' is statute miles (default)                         :*/
/*::                  'K' is kilometers                                      :*/
/*::                  'N' is nautical miles                                  :*/     
double distance(double lat1, double lon1, double lat2, double lon2, char unit);

#endif /* SERVER_H_ */
