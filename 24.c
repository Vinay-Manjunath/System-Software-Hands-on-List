/*
============================================================================
Name        : 24.c
Author      : M Vinay
Description : C program to create an Orphan process.
Date        : 1st Sept, 2025
============================================================================
Sample Output:
    $ cc 24.c
    $ ./a.out
    Parent process exiting...
    Before parent exit: Child PID: 1077, Parent PID: 1076

    After parent exit:  Child PID: 1077, Parent PID: 357
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
		printf("Before parent exit: Child PID:%d, Parent PID:%d\n",getpid(),getppid());
                sleep(15);
                printf("After parent exit: Child PID:%d, Parent PID:%d\n",getpid(),getppid());
        }

        else{
                printf("Parent process exiting...\n");
                exit(0);
        }

        return 0;
}
