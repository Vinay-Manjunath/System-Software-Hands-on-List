/*
============================================================================
Name        : 16b.c
Author      : M Vinay
Description : C program to implement a read lock.
Date        : 1st Sept, 2025
============================================================================
Sample Execution:
    $ gcc 16b.c -o 16b
    $ ./16b
    Before entering critical section:
    Entered critical section
    Exiting critical section
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
        struct flock lock;
        char* buf[15];


        lock.l_type=F_RDLCK;
        lock.l_whence=SEEK_SET;
        lock.l_start=0;
        lock.l_len=0;
        lock.l_pid=getpid();


        int fd=open("db",O_RDONLY|O_CREAT,0744);

        printf("Before entering critical section:\n");

        fcntl(fd,F_SETLKW,&lock);

        printf("Entered critical section\n");
        getchar();

        lock.l_type=F_UNLCK;

        fcntl(fd,F_SETLK,&lock);

	printf("Exiting critical section\n");
}
