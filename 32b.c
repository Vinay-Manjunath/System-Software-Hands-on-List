/*
============================================================================
Name        : 32b.c
Author      : M Vinay
Description : Protect shared memory writes using semaphore to avoid race conditions.
Date        : 30th Sept, 2025
============================================================================
Sample Execution:
$ gcc 32b.c -o 32b
$ ./32b
Shared memory updated to 10
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 5678
#define SEM_KEY 4322

void sem_wait(int semid) { struct sembuf op = {0, -1, 0}; semop(semid, &op, 1); }
void sem_signal(int semid) { struct sembuf op = {0, 1, 0}; semop(semid, &op, 1); }

int main() {
    int shmid = shmget(SHM_KEY, sizeof(int), IPC_CREAT | 0666);
    int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (shmid == -1 || semid == -1) { perror("shmget/semget"); exit(1); }

    semctl(semid, 0, SETVAL, 1);
    int *data = (int *)shmat(shmid, NULL, 0);

    sem_wait(semid);
    *data = 10;
    printf("Shared memory updated to %d\n", *data);
    sem_signal(semid);

    shmdt(data);
    return 0;
}
