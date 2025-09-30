/*
============================================================================
Name        : 30c.c
Author      : M Vinay
Description : Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 30c.c
    $ ./a.out
    Read-only attach: Data=Hello world

    Trying to overwrite...
    Segmentation fault (core dumped)
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666);

    char *data=(char*)shmat(shmid,NULL,SHM_RDONLY);
    if(data==(char*)-1){
	    perror("shmat");
	    exit(1);
    }

    printf("Read-only attach: Data=%s\n",data);

    printf("Trying to overwrite...\n");
    strcpy(data, "Overwrite attempt!");

    shmdt(data);
    return 0;
}

