/*
============================================================================
Name        : 10b.c
Author      : M Vinay
Description : Write a separate program using sigaction system call to catch the signal SIGINT
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 10b.c
    $ ./a.out
    Press Ctrl+C to exit.
    ^CYou pressed Ctrl+C (SIGINT). Program will exit.
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("You pressed Ctrl+C (SIGINT). Program will exit.\n");
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);

    printf("Press Ctrl+C to exit.\n");

    while(1) {
        sleep(1);
    }
    return 0;
}

