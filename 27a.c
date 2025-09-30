/*
============================================================================
Name        : 27a.c
Author      : M Vinay
Description : Write a program to receive messages from the message queue with 0 as a flag.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:

    root@DESKTOP-4247BS2:~/hands_on_list2# ./sender
    Enter a message to send: Hi, how are you?
    Message sent to queue (msgid=0).

    root@DESKTOP-4247BS2:~/hands_on_list2# ./recv_block
    Receiver(blocking) waiting for message
    Message received (blocking): Hi,how are you?
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MSG_SIZE 100

struct msg_buffer{
	long msg_type;
	char msg_text[MSG_SIZE];
};

int main(){
	key_t key;
	int msgid;
	struct msg_buffer message;

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

	printf("Receiver(blocking) waiting for message\n");

	if(msgrcv(msgid,&message,MSG_SIZE,1,0)==-1){
		perror("msgrcv");
		exit(1);
	}

	printf("Message received (blocking): %s\n",message.msg_text);

	return 0;
}
