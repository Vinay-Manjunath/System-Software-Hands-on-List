/*
============================================================================
Name        : 17a.c
Author      : M Vinay
Description : Write a program to execute ls -l | wc.
a. use dup
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
$ cc 17a.c
$ ./a.out
     92     820    4400
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int fd[2];
	pipe(fd);

	if(fork()==0){
		close(fd[0]);
		close(1);
		dup(fd[1]);
		close(fd[1]);
		execlp("ls","ls","-l",NULL);
	}
	else{
		close(fd[1]);
		close(0);
		dup(fd[0]);
		close(fd[0]);
		execlp("wc","wc",NULL);
		wait(0);
	}
}
