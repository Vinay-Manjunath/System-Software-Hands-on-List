/*
============================================================================
Name        : 26a.c
Author      : M Vinay
Description : C program that prints arguments passed to it. 
              This will be used as the executable program.
Date        : 5th Sept, 2025
============================================================================
Sample Output:
    $ cc 26a.c -o exec_prog
    $ ./exec_prog arg1 arg2 arg3
    Arguments passed to executable program:
    arg1
    arg2
    arg3
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc,char *argv[]){
	printf("Arguments passed to executable program:\n");
	for(int i=1;i<argc;i++){
		printf("%s\n",argv[i]);
	}
}
