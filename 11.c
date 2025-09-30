/*
============================================================================
Name        : 11.c
Author      : M Vinay
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.
Date        : 21st Sept, 2025
============================================================================Sample Execution:
    $ cc 11.c
    $ ./a.out
    SIGINT is now ignored
    ^C^C^C^C^CSIGINT is now back to default.
    ^C
============================================================================*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa;

    sa.sa_handler = SIG_IGN; 
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT is now ignored\n");
    sleep(5);

    sa.sa_handler = SIG_DFL;     
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT is now back to default.\n");

    while (1) {
        sleep(1);  
    }

    return 0;
}

