#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <sys/types.h>

#define QUEUE_NAME  "/game_queue"

#define READER      0
#define WRITER      1


typedef struct playerStr{
    char* name;
    int health;
    int mana;

} playerStr_t;

typedef struct attackStr{
    int dmg;
    int mana;
} attackStr_t;

void *readQueue(void *args)
{


    pthread_exit(NULL);
}

void *writeToQueue(void *args)
{
    printf("Thread WRITER starting...\n");

    mqd_t mq;
    char  buffer[MAX_SIZE] = "Testing queue"; // This could be taken from stdin

    /* open the queue */
    mq = mq_open(QUEUE_NAME, O_WRONLY | O_EXCL, 0700, NULL);

    /* check if the queue open is succesful */
    if (mq > -1)
    {
        /* presume, that the send is successful */
        (void) mq_send(mq, buffer, MAX_SIZE, 0);
    }
    else
    {
         printf("Failed to load queue!");
    }



}

void receiveAttack(){
    printf("Please select attack dmg! \n");
    printf("1: 10 dmg \n");
    printf("2: 40 dmg \n");

    int choice ;
    scanf("%d",&choice);
    if(choice = 1){
        attackStr.dmg = 10;
        playerStr.mana -= 15;
    }else{
        attackStr.dmg = 40;
        playerStr.mana -= 75;
    }
}

int main (int argc, char *argv[])
{
   
    playerStr_t playerStr;
    printf("Enter your name\n");
    scanf("%s",playerStr.name);
    playerStr.health = 200;
    playerStr.mana = 100;

    mqd_t          mqR,mqW;
    struct mq_attr attr;
    attackStr_t    attackStr;
    ssize_t        bytes_read  = 0;

    /* initialize the queue attributes */
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;


    while(1){
        sleep(5);
        playerStr.mana += 5 ;
        playerStr.health += 10 ;
    }

    /* create the message queue */
    mqR = mq_open(QUEUE_NAME, O_CREAT | O_RDWR | O_EXCL, 0700, &attr); 
    // Be careful with the flags - mq_open could fail, because of the creation!

    /* check if the queue open is succesful */
    if (mqR > -1)
    {
         /* receive the message */
        bytes_read = mq_receive(mqR, attackStr, sizeof(attackStr_t), NULL);
        
        if (bytes_read >= 0)
        {   
            printf("Attack Received !");
            playerStr.health -= attackStr.damage;
        }



    }
    else
    {
        printf("The game is started! Cannot connect!");
    }


   
    /* open the queue */
    mqW = mq_open(QUEUE_NAME, O_WRONLY | O_EXCL, 0700, NULL);

    /* check if the queue open is succesful */
    if (mqW > -1)
    {
        /* presume, that the send is successful */
        (void) mq_send(mqW, attackStr,sizeof(attackStr_t), 0);
    }
    else
    {
        printf("Failed to open queue!");
    }

    pthread_exit(NULL);

    return 0;
}
