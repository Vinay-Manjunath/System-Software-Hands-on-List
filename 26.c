/*
============================================================================
Name        : 26.c
Author      : M Vinay
Description : Write a program to send messages to the message queue. Check $ipcs -q 
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 26.c 
    $ ./a.out
    root@DESKTOP-4247BS2:~/hands_on_list2# ./sender
    Enter a message to send: Hi, how are you?
    Message sent to queue (msgid=0).
    root@DESKTOP-4247BS2:~/hands_on_list2# ipcs

    ------ Message Queues --------
    key        msqid      owner      perms      used-bytes   messages
    0x41304c40 0          root       666        18           1

    ------ Shared Memory Segments --------
    key        shmid      owner      perms      bytes      nattch     status


    ------ Semaphore Arrays --------
    key        semid      owner      perms      nsems
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 100

struct msgbuf{
	long mtype;
	char mtext[MSG_SIZE];
};

int main(){
	key_t key;
	int msgid;
	struct msgbuf message;

	key=ftok("msgfile",65);

	if(key==-1){
		perror("ftok");
		exit(1);
	}

	message.mtype=1;
	printf("Enter a message to send: ");
        fgets(message.mtext, MSG_SIZE, stdin);

        if(msgsnd(msgid, &message, strlen(message.mtext) + 1, 0) == -1) {
        	perror("msgsnd");
        	exit(1);
    	}

    	printf("Message sent to queue (msgid=%d).\n", msgid);

    	return 0;
}
