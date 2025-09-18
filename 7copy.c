/*
============================================================================
Name        : 7.c
Author      : M Vinay
Description : C program to copy the contents of one file (file1) into
              another file (file2) using only read() and write() system calls.
Date        : 16th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc 7.c
    $ ./a.out file1.txt file2.txt
    File copied successfully
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	
	if(argc!=3){
		fprintf(stderr,"Enter both source and destination file\n");
		return -1;
	}

	int sfd=open(argv[1],O_RDONLY);
	if(sfd==-1){
		fprintf(stderr,"Error opening the source file\n");
		return -1;
	}

	int dfd=open(argv[2],O_CREAT|O_EXCL|O_RDWR);
	if(dfd==-1){
		fprintf(stderr,"Destination file already exists\n");
		return -1;
	}

	char buffer[1024];

	int r;

	while(1){
		int r=read(sfd,buffer,sizeof(buffer));
		if(r==0){
			break;
		}
		if(r==-1){
			printf("Copy failed\n");
			return -1;
		}
		write(dfd,buffer,r);
	}
	close(sfd);
	close(dfd);
}

