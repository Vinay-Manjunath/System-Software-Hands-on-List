/*
============================================================================
Name        : 8d.c
Author      : M Vinay
Description : Write a separate program using signal system call to catch thealarm using SIGALRM
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 8d.c
    $ ./a.out
    Setting alarm for 5 seconds...
    Caught SIGALRM! Alarm triggered.
============================================================================*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM! Alarm triggered.\n");
}

int main() {
    signal(SIGALRM, handler);
    printf("Setting alarm for 5 seconds...\n");
    alarm(5);

    while(1) {
        sleep(1);
    }

    return 0;
}

