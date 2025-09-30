/*
============================================================================
Name        : 30a.c
Author      : M Vinay
Description : Write a program to create a shared memory.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 30a.c
    $ ./a.out
    Shared Memory created:ID = 1
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(){
	key_t key=ftok("shmfile",65);
	int shmid=shmget(key,SHM_SIZE,0666|IPC_CREAT);

	if(shmid==-1){
		perror("shmget");
		exit(1);
	}

	printf("Shared Memory created:ID = %d\n",shmid);
	return 0;
}
