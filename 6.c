/*
============================================================================
Name        : 6.c
Author      : M Vinay
Description : C program to take input from STDIN and display it on STDOUT
              using only read() and write() system calls.
Date        : 15th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc 6.c
    $ ./a.out
    Hello world.
    Hello world.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
	char buf[1024];

	int n;
	while((n=read(0,buf,sizeof(buf)))>0){
		write(1,buf,n);
	}
}
