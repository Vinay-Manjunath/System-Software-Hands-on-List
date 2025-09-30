/*
============================================================================
Name        : 23.c
Author      : M Vinay
Description : Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
Date        : 20st Sept, 2025
============================================================================
Sample Execution:
    $ cc 23.c
    $ ./a.out
    Maximum number of open files for this process: Soft limit:10240, Hard limit:1048576
    Size of pipe: 65536 bytes
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>

int main(){
	struct rlimit limit;

	if(getrlimit(RLIMIT_NOFILE,&limit)==0){
		printf("Maximum number of open files for this process: Soft limit:%lu, Hard limit:%lu\n",limit.rlim_cur,limit.rlim_max);
	}
	else{
		perror("getlimit");
	}

	int fd[2];
	
	pipe(fd);
	
	int psize=fcntl(fd[0],1032);
	if(psize==-1){
		perror("fcntl");
	}
	else{
		printf("Size of pipe: %d bytes\n",psize);
	}

	close(fd[0]);
	close(fd[1]);

	return 0;
}
