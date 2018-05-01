/*
 * server.h
 *
 *  Created on: Apr 9, 2018
 *      Author: yovo
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "datastruct.h"
#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>
#include<stdbool.h>
#include<sys/types.h>   
#include<sys/socket.h>
#include<pthread.h> 
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
//for distance calcuation 
#include <math.h>
#define pi 3.14159265358979323846

void* connection_handler(void *);
int loadAllTravelsFromFile(Travel* allTravelsHead,FILE *fp);
int saveTravelsToFile(Travel* allTravelsHead ,FILE *fp);
void getTravelsByStOrEndDate(void* socket_desc,Travel* currentTouristHead ,
               char* dateToCompare,bool isStartDate);
void receiveNewTravelInfo(void* socket_desc,Travel* t,char* touristName,
                                                         int* lastIdInt);
void printTravelsFromHeadNode(void* socket_desc,Travel* currentTouristHead);
int addTravel(Travel** _head,Travel* singleTravelStorage);
int getCurrentUserTravels(char* touristName, Travel* allTravelsHead,
                              Travel* currentTouristHead);
void topWantedDistances(Travel* currentTouristHead,bool topShortest,
   Travel* statisticsListPointer,int countOfTripsToReturn);
void filteredTravelsById(Travel* statisticsListPointer,
                   Travel* currentTouristHead, int* IDsOfWantedTrips,
                  int countOfTripsToReturn);

int getListSize(Travel* head);

double deg2rad(double);
double rad2deg(double);
/*:: unit = the unit you desire for results                                  :*/
/*::           where: 'M' is statute miles (default)                         :*/
/*::                  'K' is kilometers                                      :*/
/*::                  'N' is nautical miles                                  :*/     
double distance(double lat1, double lon1, double lat2, double lon2, char unit);

#endif /* SERVER_H_ */
