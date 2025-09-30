/*
============================================================================
Name        : 13b.c
Author      : M Vinay
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
$ cc 13b.c -o 13b
$ ./13b 2117
Sent SIGSTOP to process 2117
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    if (kill(pid, SIGSTOP) == 0) {
        printf("Sent SIGSTOP to process %d\n", pid);
    } else {
        perror("kill failed");
    }

    return 0;
}

