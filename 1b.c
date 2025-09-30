/*
============================================================================Name        : 1b.c
Author      : M Vinay
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_VIRTUAL
Date        : 21st Sept, 2025
============================================================================Sample Execution:
    $ cc 1b.c
    $ ./a.out
    Alarm trigger using ITIMER_VIRTUAL
    Alarm trigger using ITIMER_VIRTUAL
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void signal_handler(int signal){
        printf("Alarm trigger using ITIMER_VIRTUAL\n");
}

int main(){
        struct itimerval timer;

        signal(SIGVTALRM,signal_handler);

        timer.it_value.tv_sec=10;
        timer.it_value.tv_usec=10;
        timer.it_interval.tv_sec=10;
        timer.it_interval.tv_usec=10;

        if(setitimer(ITIMER_VIRTUAL,&timer,NULL)==-1){
                fprintf(stderr,"Error setting the timer\n");
                exit(1);
        }

        while(1){
		for(volatile long i=0;i<1000000;i++);
	}
}
