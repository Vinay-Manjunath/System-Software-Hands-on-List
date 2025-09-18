/*
============================================================================
Name        : 5.c
Author      : M Vinay
Description : C program to create five new files (f1, f2, f3, f4, f5) and
              run in an infinite loop in the background. After running, the
              file descriptors can be checked at /proc/<pid>/fd to see the
              open file table of the process.
Date        : 15th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc 5.c
    $ ./a.out &
    [1] 845

    $ ls /proc/845/fd
    0  1  2  3  4  5  6  7
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

	int fd1=open("f1",O_CREAT|O_TRUNC,0666);
	int fd2=open("f2",O_CREAT|O_TRUNC,0666);
	int fd3=open("f3",O_CREAT|O_TRUNC,0666);
        int fd4=open("f4",O_CREAT|O_TRUNC,0666);
	int fd5=open("f5",O_CREAT|O_TRUNC,0666);

	for(;;);
}
