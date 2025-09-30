/*
============================================================================
Name        : 32c.c
Author      : M Vinay
Description : Protect two pseudo resources using counting semaphore.
Date        : 30th Sept, 2025
============================================================================
Sample Execution:
$ gcc 32c.c -o 32c
$ ./32c
Resource acquired by parent process
Resource acquired by child process
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define SEM_KEY 4323

void sem_wait(int semid) { struct sembuf op = {0, -1, 0}; semop(semid, &op, 1); }
void sem_signal(int semid) { struct sembuf op = {0, 1, 0}; semop(semid, &op, 1); }

int main() {
    int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    semctl(semid, 0, SETVAL, 2);

    pid_t pid = fork();
    if (pid == 0) {
        sem_wait(semid);
        printf("Resource acquired by child process\n");
        sleep(2);
        sem_signal(semid);
    } else {
        sem_wait(semid);
        printf("Resource acquired by parent process\n");
        sleep(2);
        sem_signal(semid);
        wait(NULL);
    }

    return 0;
}

