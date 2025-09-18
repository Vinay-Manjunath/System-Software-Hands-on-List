/*
============================================================================
Name        : 29.c
Author      : M Vinay
Date        : 1st Sept, 2025
Description :
    Write a program to get scheduling policy of a process and then 
    modify the scheduling policy (to SCHED_FIFO or SCHED_RR).
============================================================================
Sample Output

$ cc 29.c
./a.out
Current scheduling policy:SCHED_OTHER
Current priority: 0

New scheduling policy:SCHED_FIFO
New priority: 50
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <string.h>

void main(){
	pid_t pid=getpid();
	struct sched_param param;

	int policy=sched_getscheduler(pid);
	printf("Current scheduling policy:");

	if(policy==SCHED_FIFO){
		printf("SCHED_FIFO\n");
	}
	else if(policy==SCHED_RR){
		printf("SCHED_RR\n");
	}
	else if(policy==SCHED_OTHER){
                printf("SCHED_OTHER\n");
        }
	else{
		printf("Unknown Policy\n");
	}

	sched_getparam(pid,&param);
	printf("Current priority: %d\n\n",param.sched_priority);

	int new_policy=SCHED_FIFO;
	param.sched_priority=50;

	sched_setscheduler(pid,new_policy,&param);

	policy=sched_getscheduler(pid);
        printf("New scheduling policy:");

        if(policy==SCHED_FIFO){
                printf("SCHED_FIFO\n");
        }
        else if(policy==SCHED_RR){
                printf("SCHED_RR\n");
        }
        else if(policy==SCHED_OTHER){
                printf("SCHED_OTHER\n");
        }
        else{
                printf("Unknown Policy\n");
        }

	sched_getparam(pid,&param);
        printf("New priority: %d\n\n",param.sched_priority);
}
