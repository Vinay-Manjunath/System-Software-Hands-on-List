/*
============================================================================
Name        : 14.c
Author      : M Vinay
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
$ cc 14.c 
$ ./a.out
Hello
Hello 
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void main(){
	int fd[2];

	pipe(fd);
	char buf[10];

	getchar();
	write(fd[1],"Hello\n",7);
	read(fd[0],buf,7);

	printf("%s\n",buf);
}

