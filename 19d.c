/*
============================================================================
Name        : 19d.c
Author      : M Vinay
Description : Create a FIFO using the mknod() system call.
Date        : 30th Sept, 2025
============================================================================
Sample Execution:
$ gcc 19d.c -o 19d
$ ./19d
FIFO created using mknod() syscall: mknod_fifo
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc,char *argv[]){
	
	char *fifo="mknod_fifo";

	if(mknod(fifo,S_IFIFO|0666,0)==-1){
		fprintf(stderr,"Error creating fifo\n");
		return 1;
	}
	printf("FIFO created using mknod() syscall:%s\n",fifo);
	return 0;
}
