/*
============================================================================
Name        : 32a.c
Author      : M Vinay
Description : Create ticket numbers using a binary semaphore to protect the critical section.
Date        : 30th Sept, 2025
============================================================================
Sample Execution:
$ gcc 32a.c -o 32a -lrt
$ ./32a
Ticket number issued: 1
Ticket number issued: 2
Ticket number issued: 3
Ticket number issued: 4
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>

#define SEM_KEY 4321

void sem_wait(int semid) {
    struct sembuf op = {0, -1, 0};
    semop(semid, &op, 1);
}

void sem_signal(int semid) {
    struct sembuf op = {0, 1, 0};
    semop(semid, &op, 1);
}

int main() {
    int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) { perror("semget"); exit(1); }

    semctl(semid, 0, SETVAL, 1);
    int ticket = 0;

    for (int i = 0; i < 4; i++) {
        sem_wait(semid);
        ticket++;
        printf("Ticket number issued: %d\n", ticket);
        sem_signal(semid);
        sleep(1);
    }

    return 0;
}

