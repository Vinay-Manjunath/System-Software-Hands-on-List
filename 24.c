/*
============================================================================
Name        : 24.c
Author      : M Vinay
Description : Write a program to create a message queue and print the key and message queue id. 
Date        : 20st Sept, 2025
============================================================================
Sample Execution:
    $ cc 24.c
    $ ./a.out
    Message Queue created successfully!
    Key:1093684288
    MsgID:0
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	key_t key;
	int msgid;
	int fd;

	fd=open("msgfile",O_CREAT|O_RDWR,0774);

	key=ftok("msgfile",65);
	if(key==-1){
		perror("ftok");
		exit(1);
	}

	msgid=msgget(key,0666|IPC_CREAT);
	if(msgid==-1){
		perror("msgget");
		exit(1);
	}

	printf("Message Queue created successfully!\n");
	printf("Key:%d\n",key);
	printf("MsgID:%d\n",msgid);
	 
	return 0;
}
