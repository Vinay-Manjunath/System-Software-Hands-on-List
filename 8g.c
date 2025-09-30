/*
============================================================================
Name        : 8g.c
Author      : M Vinay
Description : Write a separate program using signal system call to catch thesignal SIGPROF
Date        : 21st Sept, 2025
============================================================================Sample Execution:
    $ cc 8g.c
    $ ./a.out
    Caught SIGPROF!
============================================================================*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGPROF!\n");
}

int main() {
    signal(SIGPROF, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 5;
    timer.it_interval.tv_usec = 0; 

    setitimer(ITIMER_PROF, &timer, NULL);

    while(1) {
	    getpid();
    }

    return 0;
}

