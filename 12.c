/*
============================================================================
Name        : 12.c
Author      : M Vinay
Description : C program to find out the opening mode of a file using fcntl().
              It checks whether the file is opened in read-only, write-only,
              or read-write mode.
Date        : 20th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc 12.c
    $ ./a.out sample.txt
    File opened in read write mode
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc,char *argv[]){
	if(argc<2){
		printf("Please enter the file name\n");
		return;
	}
	int fd=open(argv[1],O_RDWR|O_CREAT,0744);
	
	if(fd==-1){
		printf("Error opening the file\n");
		return;
	}

	int flag=fcntl(fd,F_GETFL);

	int access=flag & O_ACCMODE;

	switch(access){
		case O_RDWR:
			printf("File opened in read write mode\n");
			break;

		case O_RDONLY:
			printf("File opened in read only mode\n");
			break;

		case O_WRONLY:
			printf("File opened in write only mode\n");
			break;

		default:
			printf("File opened in unknown mode\n");
	}
}

	
