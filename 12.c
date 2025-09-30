/*
============================================================================
Name        : 12.c
Author      : M Vinay
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 12.c
    $ ./a.out
    Child PID:2036, Parent PID:2035
    Killed
    After kill system call, Child PID:2036, Parent PID:1792
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(){
	pid_t pid=fork();

	if(pid<0){
		perror("Fork ailed");
		exit(1);
	}

	if(pid==0){
		printf("Child PID:%d, Parent PID:%d\n",getpid(),getppid());
		kill(getppid(),SIGKILL);
		sleep(5);
		printf("After kill system call, Child PID:%d, Parent PID:%d\n",getpid(),getppid());
	}
	else{
		while(1){
			sleep(1);
		}
	}

	return 0;
}

