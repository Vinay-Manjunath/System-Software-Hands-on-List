/*
============================================================================
Name        : 15.c
Author      : M Vinay
Description : Write a simple program to send some data from parent to the child process.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
$ cc 15.c
$ ./a.out
Hello
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

void main(){
	int fd[2];
	pipe(fd);
	char buf[10];

	if(!fork()){
		close(fd[0]);
		write(fd[1],"Hello\n",7);
	}
	else{
		close(fd[1]);
		read(fd[0],buf,7);
		printf("%s\n",buf);
		wait(0);
	}
}

