/*
============================================================================
Name        : 25.c
Author      : M Vinay
Description : C program to create three child processes. 
              The parent waits for a particular child using waitpid().
Date        : 5th Sept, 2025
============================================================================
Sample Output:
    $ cc 25.c
    $ ./a.out
    Child 0 process, pid:1089, ppid:1088
    Parent process, pid:1234
    Child 1 process, pid:1090, ppid:1088
    Child 2 process, pid:1091, ppid:1088
    Child 1 exited with status 0, parent exiting
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void main(){
	pid_t pid[3];
	int status;

	for(int i=0;i<3;i++){
		pid[i]=fork();

		if(pid[i]<0){
			fprintf(stderr,"Fork failed\n");
			exit(1);
		}
		if(pid[i]==0){
			printf("Child %d process, pid:%d, ppid:%d\n",i,getpid(),getppid());
			exit(0);
		}
	}

	printf("Parent process, pid:%d\n",getpid());
	waitpid(pid[1],&status,0);
	printf("Child 1 exited with status %d, parent exiting\n",status);
	exit(0);
}

