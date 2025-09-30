/*
============================================================================
Name        : 10c.c
Author      : M Vinay
Description : Write a separate program using sigaction system call to catch the signal SIGFPE
Date        : 21st Sept, 2025
===========================================================================
Sample Execution:
    $ cc 10c.c
    $ ./a.out
    Floating point error caught (SIGFPE)
============================================================================*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void fpe_handler(int sig) {
    printf("Floating point error caught (SIGFPE)\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = fpe_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGFPE, &sa, NULL);

    int x = 10, y = 0;
    int z = x / y;  

    printf("Result = %d\n", z);
    return 0;
}

