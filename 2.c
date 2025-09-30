/*
============================================================================Name        : 2.c
Author      : M Vinay
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date        : 21st Sept, 2025
============================================================================Sample Execution:
    $ cc 2.c
    $ ./a.out
    System Resource Limits:
    CPU time (seconds):soft=unlimited, hard = unlimited
    Maximum file size (bytes):soft=unlimited, hard = unlimited
    Data segment size (bytes):soft=unlimited, hard = unlimited
    Stack size (bytes):soft = 8388608, hard = unlimited
    Core file size (bytes):soft = 0, hard = unlimited
    Maximum open files:soft = 10240, hard = 1048576
    Virtual memory size (bytes):soft=unlimited, hard = unlimited
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void display_limit(int resource,char *name){
	struct rlimit limit;

	if(getrlimit(resource,&limit)==-1){
		perror("getrlimit");
		return;
	}

	printf("%s:",name);

	if(limit.rlim_cur==RLIM_INFINITY)
		printf("soft=unlimited, ");
	else
        	printf("soft = %lu, ", limit.rlim_cur);

    	if (limit.rlim_max == RLIM_INFINITY)
        	printf("hard = unlimited\n");
    	else
        	printf("hard = %lu\n", limit.rlim_max);
}

int main() {
    printf("System Resource Limits:\n");

    display_limit(RLIMIT_CPU, "CPU time (seconds)");
    display_limit(RLIMIT_FSIZE, "Maximum file size (bytes)");
    display_limit(RLIMIT_DATA, "Data segment size (bytes)");
    display_limit(RLIMIT_STACK, "Stack size (bytes)");
    display_limit(RLIMIT_CORE, "Core file size (bytes)");
    display_limit(RLIMIT_NOFILE, "Maximum open files");
    display_limit(RLIMIT_AS, "Virtual memory size (bytes)");

    return 0;
}
