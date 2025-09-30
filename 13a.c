/*
============================================================================
Name        : 13a.c
Author      : M Vinay
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
$ cc 13a.c -o 13a
$ ./13a
PID: 2117
Waiting for SIGSTOP...

[2]+  Stopped                 ./13a
============================================================================*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig){
	printf("Caught signal %d\n",sig);
}

int main(){
	printf("PID: %d\n", getpid());
        printf("Waiting for SIGSTOP...\n");
	signal(SIGSTOP,handler);


	while(1){
		sleep(2);
	}
	return 0;
}
