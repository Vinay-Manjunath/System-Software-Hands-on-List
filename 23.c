/*
============================================================================
Name        : 23.c
Author      : M Vinay
Description : C program to create a Zombie process.
Date        : 1st Sept, 2025
============================================================================
Sample Output:
    $ cc 23.c
    $ ./a.out
    Parent process starts sleeping
    Child process (PID: 565) exiting...

    $ ps aux | grep 565
    root         565  0.0  0.0      0     0 pts/2    Z+   10:22   0:00 [a.out] <defunct>

    Parent process finished sleeping
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	pid_t pid=fork();
	
	if(pid<0){
		fprintf(stderr,"Fork failed\n");
		exit(1);
	}

	if(pid==0){
		printf("Child process (PID:%d) exiting.....\n",getpid());
		exit(0);
	}

	else{
		printf("Parent process starts sleeping\n");
		sleep(30);
		printf("Parent process finished sleeping\n");
	}

	return 0;
}
