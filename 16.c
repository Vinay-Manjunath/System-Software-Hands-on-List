/*
============================================================================
Name        : 16.c
Author      : M Vinay
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
$ cc 16.c
$ ./a.out
From parent to child process: Hi, How are you?

From child to parent process: I am fine
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
	int fd[2];
	int fd1[2];
	pipe(fd);
	pipe(fd1);
	char iread[100],buf[100];

	if(!fork()){
		close(fd[0]);
		
		sprintf(iread,"I am fine\n");
		write(fd[1],iread,sizeof(iread));

		close(fd1[1]);

		read(fd1[0],buf,sizeof(buf));
		printf("From parent to child process: %s\n",buf);
	}
	else{
                close(fd1[0]);

                sprintf(iread,"Hi, How are you?\n");
                write(fd1[1],iread,sizeof(iread));

                close(fd[1]);

                read(fd[0],buf,sizeof(buf));
                printf("From child to parent process: %s\n",buf);
	}
}

