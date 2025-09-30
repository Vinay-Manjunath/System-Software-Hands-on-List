/*
============================================================================
Name        : 30e.c
Author      : M Vinay
Description : Write a program to create a shared memory.remove the shared memory
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 30e.c
    $ ./a.out

    Shared memory removed.
============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666);

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    printf("Shared memory removed.\n");
    return 0;
}
