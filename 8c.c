/*
============================================================================
Name        : 8c.c
Author      : M Vinay
Description : Write a separate program using signal system call to catch thesignal SIGFPE
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 8c.c
    $ ./a.out
    Caught SIGFPE! Division by zero.
============================================================================*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGFPE! Division by zero.\n");
    exit(1);
}

int main() {
    signal(SIGFPE, handler);

    int x = 10;
    int y = 0;
    int z = x / y;

    printf("Result = %d\n", z);

    return 0;
}

