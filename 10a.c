/*
============================================================================
Name        : 10a.c
Author      : M Vinay
Description : Write a separate program using sigaction system call to catch the signal SIGSEGV
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 10a.c
    $ ./a.out
    Segmentation fault caught (SIGSEGV)
============================================================================*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void segv_handler(int sig) {
    printf("Segmentation fault caught (SIGSEGV)\n");
    exit(1);   
}

int main() {
    struct sigaction sa;
    sa.sa_handler = segv_handler;  
    sa.sa_flags = 0;               
    sigemptyset(&sa.sa_mask);      

    sigaction(SIGSEGV, &sa, NULL); 

    int *p = NULL;
    *p = 5;

    return 0;
}

