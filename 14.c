/*
============================================================================
Name        : 14.c
Author      : M Vinay
Description : C program to find the type of a file. The program takes the
              filename as a command-line argument and identifies whether
              it is a regular file, directory, character device, block
              device, FIFO (named pipe), socket, or symbolic link.
Date        : 20th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc 14.c
    $ ./a.out 9.c
    Regular file

    $ ./a.out /dev/null
    Character Special File

    $ ./a.out /tmp
    Directory

    $ ./a.out myfifo
    FIFO, named pipe
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void main(int argc,char *argv[]){
	if(argc<2){
		printf("Enter the file name:\n");
		exit(-1);
	}

	struct stat fstat;

	if(stat(argv[1],&fstat)==-1){
		printf("Stat failed\n");
		exit(-1);
	}

	if(S_ISREG(fstat.st_mode)){
		printf("Regular file\n");
	}
	else if(S_ISDIR(fstat.st_mode)){
                printf("Directory\n");
        }
	else if(S_ISCHR(fstat.st_mode)){
                printf("Character Special File\n");
        }
	else if(S_ISBLK(fstat.st_mode)){
                printf("Block Special File\n");
        }
	else if(S_ISFIFO(fstat.st_mode)){
                printf("FIFO, named pipe\n");
        }
	else if(S_ISSOCK(fstat.st_mode)){
                printf("Socket file\n");
        }
	else if(S_ISLNK(fstat.st_mode)){
                printf("Symbolic Link\n");
        }
	else{
		printf("Unknown file type\n");
	}
}
