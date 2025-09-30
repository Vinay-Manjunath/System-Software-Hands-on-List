/*
============================================================================
Name        : 6.c
Author      : M Vinay
Description : Write a simple program to create three threads. 
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 6.c
    $ ./a.out
    Hello from Thread 1
    Hello from Thread 2
    Hello from Thread 3
    All threads finished
============================================================================*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *myThread(void *argp){
	int id= *(int*)argp;
	printf("Hello from Thread %d\n",id);
	sleep(10);
	return NULL;
}

int main(){
	pthread_t tid[3];
	int ids[3]={1,2,3};

	for(int i=0; i<3; i++)
        	pthread_create(&tid[i], NULL, myThread, &ids[i]);

    	for(int i=0; i<3; i++)
        	pthread_join(tid[i], NULL);

	printf("All threads finished\n");
	return 0;
}
