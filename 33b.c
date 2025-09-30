/*
============================================================================
Name        : 33b.c
Author      : M Vinay
Description : Write a program to communicate between two machines using socket.(Client program)
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 33b.c -o client
    $ ./client
    Connected to server
    Enter message:Hello world
    Message from server:ACK from Server

    Enter message:Hi How are you
    Message from server:ACK from Server 
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sd;
    struct sockaddr_in serv;
    char buf[80];

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("socket");
        exit(1);
    }

    serv.sin_family = AF_INET;
    serv.sin_port = htons(5055);
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sd, (struct sockaddr*)&serv, sizeof(serv)) < 0) {
        perror("connect");
        exit(1);
    }
    printf("Connected to server\n");

    while(1){
    	printf("Enter message to send to server: ");
    	fgets(buf, sizeof(buf), stdin);

        write(sd, buf, strlen(buf)+1);

	memset(buf,0,sizeof(buf));
    	read(sd, buf, sizeof(buf));
    	printf("Message from Server: %s\n", buf);
    }

    close(sd);
    return 0;
}
