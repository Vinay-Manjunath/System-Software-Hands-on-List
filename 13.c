/*
============================================================================
Name        : 13.c
Author      : M Vinay
Description : C program to wait for STDIN for 10 seconds using select().
              If data is available within 10 seconds, it reads and prints
              the data; otherwise, it prints a timeout message.
Date        : 20th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc 13.c
    $ ./a.out
    Timeout, no data obtained within 10 seconds

    $ ./a.out
    Hello
    Data received: Hello
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/select.h>

void main(){
	fd_set readfd;
	struct timeval timeout;

	FD_ZERO(&readfd);
	FD_SET(0,&readfd);

	timeout.tv_sec=10;
	timeout.tv_usec=0;

	int res=select(1,&readfd,NULL,NULL,&timeout);

	if(res==-1){
		printf("Select failed\n");
		exit(-1);
	}
	else if(res==0){
		printf("Timeout, no data obtained within 10 seconds\n");
	}
	else{
		char buffer[1024];
		int n=read(0,buffer,sizeof(buffer));
		if(n>0){
			buffer[n]='\0';
			printf("Data received:%s\n",buffer);
		}
		else{
			printf("No Data\n");
		}
	}
}
