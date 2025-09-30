/*
============================================================================
Name        : 31a.c
Author      : M Vinay
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 31a.c
    $ ./a.out
    Binary semaphore created with ID = 1 and value = 1
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("semfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl");
        exit(1);
    }

    printf("Binary semaphore created with ID = %d and value = 1\n", semid);
    return 0;
}

