/*
============================================================================
Name        : 32d.c
Author      : M Vinay
Description : Remove the created semaphore from the system.
Date        : 30th Sept, 2025
============================================================================
Sample Execution:
$ gcc 32d.c -o 32d
$ ./32d
Semaphore removed successfully
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>

#define SEM_KEY 4321

int main() {
    int semid = semget(SEM_KEY, 1, 0666);
    if (semid == -1) { perror("semget"); exit(1); }

    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl remove");
        exit(1);
    }

    printf("Semaphore removed successfully\n");
    return 0;
}

