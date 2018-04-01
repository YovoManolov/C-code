#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buffer{
	long mesg_type;
	char mesg_text[100];
}message;

/*ftok() - use to generate a unique key
msgget() - ether returns the message queue identifier
	for the newly created message queue or returns the identifier
	for the MQ witch exists with the same key value
msgrcv() - messages are retrieved from a queue
msgctl() - preforms various operations on a queue. Generally
	it is use to destroy message queue.*/


int main(){
	key_t key;
	int msgid;

	/*ключът ни трябва, за да достъпим id na MQ, 
	a Id ni e nujno za da izpolzwavme messageQueue za 
	izprashtane i poluchavane na syobshteniq.*/

	key = ftok("progfile", 65);
	msgid = msgget(key,0666| IPC_CREAT);
	message.mesg_type = 1;

	printf("Write data : ");
	gets(message.message_text);

	msgsnd(msgid, &message, sizeof(message),0);
	printf("Data send is: %s\n", message.mesg_text);

	return 0;
}