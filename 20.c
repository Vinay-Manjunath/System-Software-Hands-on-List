/*
============================================================================
Name        : 20.c
Author      : M Vinay
Description : C program to find the priority (nice value) of the current process
              and modify it using nice().
Date        : 1st Sept, 2025
Sample Output:
    $ cc 20.c
    $ ./a.out
    PID: 1014, initial nice value: 0
    New nice value: 5
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/resource.h>

void main(){
	int pid=getpid();

	int priority=getpriority(PRIO_PROCESS,pid);
	if(priority==-1){
		fprintf(stderr,"Error in getting the priority\n");
		exit(1);
	}
	printf("PID: %d, initial nice value: %d\n", pid,priority);

	int new_priority=nice(5);

	if(new_priority==-1){
		fprintf(stderr,"Error in setting the nice value\n");
		exit(1);
	}
	new_priority=getpriority(PRIO_PROCESS,pid);
	printf("New nice value: %d\n", new_priority);
}
