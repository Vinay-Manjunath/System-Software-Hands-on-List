/*
============================================================================
Name        : 22.c
Author      : M Vinay
Description : C program to demonstrate fork() writing to a file from both 
              parent and child processes. Observe the file output.
Date        : 1st Sept, 2025
Sample Output:
    $ gcc 22.c 
    $ ./a.out
    $ cat 22.txt
    Written by parent process, pid:1045
    Written by child process, pid:1046
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd;
	char buffer[100];

	fd=open("22.txt",O_WRONLY|O_CREAT);

	if(fork()){
		sprintf(buffer,"Written by parent process, pid:%d\n",getpid());
		write(fd,buffer,sizeof(buffer));
	}

	else{
		sprintf(buffer,"Written by child process, pid:%d\n",getpid());
                write(fd,buffer,sizeof(buffer));
	}
}
