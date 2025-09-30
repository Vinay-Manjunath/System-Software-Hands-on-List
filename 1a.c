/*
============================================================================
Name        : 1a.c
Author      : M Vinay
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 1a.c
    $ ./a.out
    Alarm trigger using ITIMER_REAL
    Alarm trigger using ITIMER_REAL
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void signal_handler(int signal){
	printf("Alarm trigger using ITIMER_REAL\n");
}

int main(){
	struct itimerval timer;

	signal(SIGALRM,signal_handler);

	timer.it_value.tv_sec=10;
	timer.it_value.tv_usec=10;
	timer.it_interval.tv_sec=10;
        timer.it_interval.tv_usec=10;

	if(setitimer(ITIMER_REAL,&timer,NULL)==-1){
		fprintf(stderr,"Error setting the timer\n");
		exit(1);
	}

	while(1) pause();
}
