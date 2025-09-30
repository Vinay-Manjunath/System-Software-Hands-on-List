/*
============================================================================
Name        : 8e.c
Author      : M Vinay
Description : Write a separate program using signal system call to catch thesignal SIGALRM (using setitimer)
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 8a.c
    $ ./a.out
    Caught SIGALRM via setitimer!
    Caught SIGALRM via setitimer!
============================================================================*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM via setitimer!\n");
}

int main() {
    signal(SIGALRM, handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 5;     
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 5;  
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while(1) sleep(1);

    return 0;
}

