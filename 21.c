/*
============================================================================
Name        : 21.c
Author      : M Vinay
Description : C program to demonstrate fork(). Prints parent and child process IDs.
Date        : 1st Sept, 2025
Sample Output:
    $ cc 21.c
    $ ./a.out
    Parent process, pid:1022
    Child process, pid:1023, ppid:1022`
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
	if(!fork()){
		printf("Child process, pid:%d, ppid:%d\n",getpid(),getppid());
	}
	else{
		printf("Parent process, pid:%d\n",getpid());
	}
}

