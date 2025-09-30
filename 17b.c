/*
============================================================================
Name        : 17b.c
Author      : M Vinay
Description : Write a program to execute ls -l | wc.
a. use dup2
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
$ cc 17b.c
$ ./a.out
     92     820    4400
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int fd[2];
	pipe(fd);

	if(fork()==0){
		close(fd[0]);
		dup2(fd[1],1);
		close(fd[1]);
		execlp("ls","ls","-l",NULL);
	}
	else{
		close(fd[1]);
		dup2(fd[0],0);
		close(fd[0]);
		execlp("wc","wc",NULL);
	}
}
