/*
============================================================================
Name        : 3.c
Author      : M Vinay
Description : C program to create a new file (name taken from command-line
              argument) and print its file descriptor value using the creat()
              system call.
Date        : 14th Aug, 2025
============================================================================
Sample Execution & Output:
    $ cc 3.c
    $ ./a.out myfile.txt
    File descriptor value: 3

    $ ls -l myfile.txt
    -rw-r--r-- 1 root root 0 Aug 14 23:55 myfile.txt
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd;

    if (argc < 2) {
        fprintf(stderr,"Enter the filename\n");
        exit(1);
    }

    fd = creat(argv[1], 0666);
    if (fd == -1) {
        fprintf(stderr,"Error creating the file");
        return 1;
    }

    printf("File descriptor value: %d\n", fd);
	
    close(fd);
    return 0;
}

