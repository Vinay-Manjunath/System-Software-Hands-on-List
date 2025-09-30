/*
============================================================================
Name        : 30b.c
Author      : M Vinay
Description : Write a program to create a shared memory.
a. write some data to the shared memory
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 30b.c
    $ ./a.out
    Hello world
    Data written:Hello world
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main(){
	key_t key=ftok("shmfile",65);
	int shmid=shmget(key,SHM_SIZE,0666);

	char *data=(char*)shmat(shmid,NULL,0);
	if(data==(char*)-1){
		perror("shmat");
		exit(1);
	}

	fgets(data,SHM_SIZE,stdin);

	printf("Data written:%s\n",data);

	shmdt(data);
	return 0;
}
