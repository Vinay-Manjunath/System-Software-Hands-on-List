/*
============================================================================
Name        : 11.c
Author      : M Vinay
Description : C program to open a file, duplicate the file descriptor using
              dup(), dup2(), and fcntl(F_DUPFD), append data using all
              descriptors, and verify that the file is updated properly.
Date        : 20th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc a.c
    $ ./a.out sample.txt

    $ cat sample.txt
    Using original file descriptor Using dup Using dup 2 Using fcntl
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void main(int argc,char *argv[]){
	int fd=open(argv[1],O_CREAT|O_RDWR,0744);
	if(fd<0){
		printf("Error opeing the file\n");
		return;
	}

	int newfd=dup(fd);

	write(fd,"Using original file descriptor ",strlen("Using original file descriptor "));
	write(newfd,"Using dup ",strlen("Using dup "));

	int dup2fd=100;
	dup2(fd,dup2fd);

        write(dup2fd,"Using dup 2 ",strlen("Using dup 2 "));

	int fcntlfd=fcntl(fd,F_DUPFD,101);
	write(fcntlfd,"Using fcntl ",strlen("Using fcntl "));
	//getchar();
	close(fd);
    	close(newfd);
    	close(dup2fd);
    	close(fcntlfd);
}
