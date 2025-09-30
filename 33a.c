/*
============================================================================
Name        : 33a.c
Author      : M Vinay
Description : Write a program to communicate between two machines using socket.(Server program)
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 33a.c -o server
    $ ./server
    Server waiting for client...
    Client connected
    Message from Client:Hello world

    Message from Client:Hi How are you
 
============================================================================*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <arpa/inet.h>

int main(){
	struct sockaddr_in serv,cli;
	int sd,nsd,sz;
	char buf[80];
	sd=socket(AF_INET,SOCK_STREAM,0);

	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_port=htons(5055);

	bind(sd,(void *)(&serv),sizeof(serv));

	listen(sd,5);
	sz=sizeof(cli);

	printf("Server waiting for client...\n");
	nsd=accept(sd,(void *)(&cli),&sz);
	if(nsd<0) exit(1);
	printf("Client connected\n");

	while(1){
		memset(buf,0,sizeof(buf));
		read(nsd,buf,sizeof(buf));
		printf("Message from Client:%s\n",buf);
		write(nsd,"ACK from Server\n",17);
	}

	close(nsd);
	close(sd);
	return 0;
}
