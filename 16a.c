/*
============================================================================
Name        : 16a.c
Author      : M Vinay
Description : C program to implement a write lock.
Date        : 1st Sept, 2025
============================================================================
Sample Execution:
    $ gcc 16a.c -o 16a
    $ ./16a
    Before entering critical section:
    Entered critical section
    Exiting critical section
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void main(){
        struct flock lock;
        char buf[150];


        lock.l_type=F_WRLCK;
        lock.l_whence=SEEK_SET;
        lock.l_start=0;
        lock.l_len=0;
        lock.l_pid=getpid();


        int fd=open("db",O_WRONLY,0744);

        printf("Before entering critical section:\n");

        fcntl(fd,F_SETLKW,&lock);

        printf("Entered critical section\n");
	getchar();
	strcpy(buf,"Writing to file using write lock");
        write(fd,buf,sizeof(buf));

        lock.l_type=F_UNLCK;

        fcntl(fd,F_SETLK,&lock);

	printf("Exiting critical section\n");
}
