/*
============================================================================
Name        : 3.c
Author      : M Vinay
Description : Write a program to set (any one) system resource limit. Use setrlimit system call. 
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 3.c
    $ ./a.out
    Limits for max open files (before changing):
    Soft limit = 10240, Hard limit = 1048576
    Limits for max open files (after changing):
    Soft limit = 512, Hard limit = 1048576
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(){
	struct rlimit limit;

	if(getrlimit(RLIMIT_NOFILE,&limit)==-1){
		perror("getlimit");
		exit(1);
	}

	printf("Limits for max open files (before changing):\n");
	printf("Soft limit = %lu, Hard limit = %lu\n", limit.rlim_cur, limit.rlim_max);

	limit.rlim_cur=512;

	if(setrlimit(RLIMIT_NOFILE,&limit)==-1){
		perror("setlimi");
		exit(1);
	}

	if(getrlimit(RLIMIT_NOFILE,&limit)==-1){
                perror("getlimit");
                exit(1);
        }

        printf("Limits for max open files (after changing):\n");
        printf("Soft limit = %lu, Hard limit = %lu\n", limit.rlim_cur, limit.rlim_max);

	return 0;
}
