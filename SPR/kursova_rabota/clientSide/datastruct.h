/*
 * server.h
 *
 *  Created on: Apr 9, 2018
 *      Author: yovo
 */

#ifndef DATASTRUCT_H_
#define DATASTRUCT_H_


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

#endif /* DATASTRUCT_H_ */