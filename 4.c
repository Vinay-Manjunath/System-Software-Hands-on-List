/*
============================================================================
Name        : 4.c
Author      : M Vinay
Description : C program to demonstrate opening an existing file in read-write
              mode using open(), and testing the O_EXCL flag.
Date        : 14th Aug, 2025
============================================================================
Sample Execution & Output:

    Case 1: File exists
    $ echo "hello" > file1
    $ cc 4.c
    $ ./4.out
    File Descriptor for file opened in Read Write Mode: 3
    File already exists

    Case 2: File does not exist
    $ rm file1
    $ ./4.out
    File does not exist
    File descriptor of new file: 3

============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main(){
	int fd=open("file1",O_RDWR);
	if(fd==-1){
		printf("File does not exists\n");
	}
	else{
		printf("File Descriptor for file opened in Read Write Mode:%d\n",fd);
		close(fd);
	}

	fd=open("file1",O_CREAT|O_EXCL,0744);
	if(fd==-1){
		printf("File already exists\n");
	}
	else{
		printf("File descriptor of new file:%d\n",fd);
		close(fd);
	}
}
