/*
============================================================================
Name        : 8a.c
Author      : M Vinay
Description : Write a separate program using signal system call to catch thesignal SIGSEGV
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 8a.c
    $ ./a.out
    Caught SIGSEGV! Segmentation Fault.
============================================================================*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGSEGV! Segmentation Fault.\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, handler);

    int *p = NULL;
    *p = 10;

    return 0;
}

