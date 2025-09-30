/*
============================================================================
Name        : 8b.c
Author      : M Vinay
Description : Write a separate program using signal system call to catch thesignal SIGINT
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 8b.c
    $ ./a.out
    Press Ctrl+C to trigger SIGINT...
    ^C
    Caught SIGINT (Ctrl+C)! Exiting...
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("\nCaught SIGINT (Ctrl+C)! Exiting...\n");
    exit(0);
}

int main() {
    signal(SIGINT, handler);

    printf("Press Ctrl+C to trigger SIGINT...\n");
    while(1) {
        sleep(1);
    }

    return 0;
}

