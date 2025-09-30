/*
============================================================================
Name        : 22.c
Author      : M Vinay
Description : Wait for data to be written into FIFO within 10 seconds using select() system call.
Date        : 30th Sept, 2025
============================================================================
Sample Execution:
$ gcc 22.c -o 22
$ ./22
Received Data: Hello FIFO
//or
Timeout, no data written to fifo
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
	fd_set fifofd;
	struct timeval timeout;

	mkfifo("22fifo", 0666);
	int fd=open("22fifo",O_RDONLY|O_NONBLOCK);

	FD_ZERO(&fifofd);
	FD_SET(fd,&fifofd);

	timeout.tv_sec=10;
	timeout.tv_usec=0;

	int res=select(fd+1,&fifofd,NULL,NULL,&timeout);

	if(res==-1){
		printf("Select failed\n");
		exit(-1);
	}
	else if(res==0){
		printf("Timeout, no data written to fifo\n");
	}
	else{
		char buffer[100];
		int n=read(fd,buffer,sizeof(buffer)-1);
		if(n>0){
			buffer[n]='\0';
			printf("Received Data:%s\n",buffer);
		}
	}
	close(fd);
	return 0;
}

