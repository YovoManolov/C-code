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

void clearScreen();
void printMenu();
void readMessageFromServer(int sock,char* server_message, int sizeOfMessage);
int addNewTrip(int sock,char* server_message);

#endif /* CLIENT_H_ */
