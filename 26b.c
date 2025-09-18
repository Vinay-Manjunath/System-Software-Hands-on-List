/*
============================================================================
Name        : 26b.c
Author      : M Vinay
Description : C program to execute another executable (`exec_prog`) 
              using execl(). The child process replaces itself with 
              `exec_prog` and passes arguments to it.
Date        : 5th Sept, 2025
============================================================================
Sample Output:
    $ cc 26b.c -o exec_runner
    $ ./exec_runner
    Parent process, pid: 1231
    Child process, pid: 1232, Parent pid: 1231
    Arguments passed to executable program:
    arg1
    arg2
    arg3
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

void main(){
	if(!fork()){
		printf("Child process,pid: %d, Parent pid:%d\n",getpid(),getppid());
		execl("./exec_prog","./exec_prog","arg1","arg2","arg3",NULL);
		exit(0);
	}
	else{
		printf("Parent process,pid: %d\n",getpid());
		wait(0);
	}
}
