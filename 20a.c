/*
============================================================================
Name        : 20a.c
Author      : M Vinay
Description : Write a message to a FIFO (one-way communication).
Date        : 30th Sept, 2025
============================================================================
Sample Execution:
$ gcc 20a.c -o 20a
$ ./20a
Message sent to FIFO
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(){
	char *fifo="20fifo";

	mkfifo(fifo,0666);

	int fd=open(fifo,O_WRONLY);
	if(fd==-1){
		fprintf(stderr,"Error opening the fifo\n");
		return 1;
	}

	char message[]="Hi! How are you?";
	write(fd,message,strlen(message)+1);

	close(fd);
	return 0;
}
