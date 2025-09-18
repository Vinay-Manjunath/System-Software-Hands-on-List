/*
============================================================================
Name : 28_realtime_priority.c
Author : Your Name
Date : 5st Sept, 2025
Description :
    Write a program to get maximum and minimum real time priority
    for different scheduling policies.
    Policies checked:
        - SCHED_FIFO
        - SCHED_RR
        - SCHED_OTHER
============================================================================
Sample Output:

SCHED_FIFO: Min = 1, Max = 99
SCHED_RR:   Min = 1, Max = 99
SCHED_OTHER: Min = 0, Max = 0
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>

void main(){
	int policies[] = {SCHED_FIFO,SCHED_RR,SCHED_OTHER};
	char *names[]={"SCHED_FIFO","SCHED_RR","SCHED_OTHER"};

	for(int i=0;i<3;i++){
		int max=sched_get_priority_max(policies[i]);
		int min=sched_get_priority_min(policies[i]);

		if(max==-1 || min==-1){
			fprintf(stderr,"Error in getting priority\n");
		}
		else{
			printf("%s: Min=%d, Max=%d\n", names[i],min,max);
		}
	}
}
