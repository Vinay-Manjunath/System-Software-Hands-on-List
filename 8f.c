/*
============================================================================
Name        : 8f.c
Author      : M Vinay
Description : Write a separate program using signal system call to catch thesignal SIGVTALRM
Date        : 21st Sept, 2025
============================================================================Sample Execution:
    $ cc 8f.c
    $ ./a.out
    Caught SIGVTALRM!.
============================================================================*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGVTALRM!\n");
}

int main() {
    signal(SIGVTALRM, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0; 
    timer.it_interval.tv_sec = 5;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while(1) {
        for(volatile long i = 0; i < 1000000; i++);
    }

    return 0;
}

