/*
============================================================================
Name        : 31b.c
Author      : M Vinay
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a counting semaphore
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 31b.c
    $ ./a.out
    Counting semaphore created with ID = 0 and value = 5
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("semfile", 66);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int sem_count = 5;
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    if (semctl(semid, 0, SETVAL, sem_count) == -1) {
        perror("semctl");
        exit(1);
    }

    printf("Counting semaphore created with ID = %d and value = %d\n", semid, sem_count);
    return 0;
}

