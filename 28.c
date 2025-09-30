/*
============================================================================
Name        : 27a.c
Author      : M Vinay
Description : Write a program to receive messages from the message queue with 0 as a flag.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 28.c
    $ ./a.out
    Current permissions:666
    Enter new permissions:644
    New permissions set:644
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main(){
	key_t key;
	int msgid;
	unsigned int new_mode;
	struct msqid_ds buf;

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

	if(msgctl(msgid,IPC_STAT,&buf)==-1){
		perror("msgctl (IPC_STAT)");
		exit(1);
	}

	printf("Current permissions:%o\n",buf.msg_perm.mode);

	printf("Enter new permissions:");
	if(scanf("%o",&new_mode)!=1){
		fprintf(stderr,"Invalid input\n");
		exit(1);
	}

	buf.msg_perm.mode=new_mode;

	if(msgctl(msgid,IPC_SET,&buf)==-1){
		perror("msgctl (IPC_SET)");
		exit(1);
	}

	printf("New permissions set:%o\n",buf.msg_perm.mode);

	return 0;
}

