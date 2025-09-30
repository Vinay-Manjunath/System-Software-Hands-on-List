/*
============================================================================
Name        : 7.c
Author      : M Vinay
Description : Write a simple program to print the created thread ids. 
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
$ cc 7.c
$ ./a.out
Thread created with Id 135912400877120
Thread created with Id 135912384091712
Thread created with Id 135912392484416
============================================================================*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *myThread(void *argp){
	printf("Thread created with Id %lu\n",pthread_self());
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
