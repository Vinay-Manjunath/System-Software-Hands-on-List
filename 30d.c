/*
============================================================================
Name        : 30d.c
Author      : M Vinay
Description : Write a program to create a shared memory.detach the shared memory
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 30d.c
    $ ./a.out
    Data before detach: Hello world

    Shared memory detached.
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666);

    char *data = (char*)shmat(shmid, NULL, 0);
    if (data == (char*)-1) {
        perror("shmat");
        exit(1);
    }

    printf("Data before detach: %s\n", data);

    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    printf("Shared memory detached.\n");
    return 0;
}

