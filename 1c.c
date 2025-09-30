/*
============================================================================Name        : 1c.c
Author      : M Vinay
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_PROF
Date        : 21st Sept, 2025
============================================================================Sample Execution:
    $ cc 1c.c
    $ ./a.out
    Alarm trigger using ITIMER_PROF
    Alarm trigger using ITIMER_PROF
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void signal_handler(int signal){
        printf("Alarm trigger using ITIMER_PROF\n");
}

int main(){
        struct itimerval timer;

        signal(SIGPROF,signal_handler);

        timer.it_value.tv_sec=10;
        timer.it_value.tv_usec=10;
        timer.it_interval.tv_sec=10;
        timer.it_interval.tv_usec=10;

        if(setitimer(ITIMER_PROF,&timer,NULL)==-1){
                fprintf(stderr,"Error setting the timer\n");
                exit(1);
        }

        while(1) getpid();
}
