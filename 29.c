/*
============================================================================
Name        : 29.c
Author      : M Vinay
Description : Write a program to remove the message queue.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 27a.c
    $ ./a.out
    Message queue (msgid=2) removed successfully
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main(){
	key_t key;
	int msgid;

	key=ftok("msgfile",65);
	if(key==-1){
		perror("ftok");
		exit(1);
	}

	msgid=msgget(key,0666);
	if(msgid==-1){
		perror("msgget");
		exit(1);
	}

	if(msgctl(msgid,IPC_RMID,NULL)==-1){
		exit(1);
	}

	printf("Message queue (msgid=%d) removed successfully.\n",msgid);

	return 0;
}
