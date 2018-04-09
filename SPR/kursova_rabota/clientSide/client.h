/*
 * client.h
 *
 *  Created on: Apr 9, 2018
 *      Author: yovo
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include<stdio.h> //printf
#include<stdlib.h> //exit(0);
#include<string.h>    //strlen
#include<unistd.h>
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#define clear() printf("\033[H\033[J")

void printMenu();

#endif /* CLIENT_H_ */
