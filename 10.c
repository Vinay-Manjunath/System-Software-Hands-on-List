/*
============================================================================
Name        : 10.c
Author      : M Vinay
Description : C program to open a file in read-write mode, write 10 bytes,
              move the file pointer by 10 bytes using lseek(), and write
              another 10 bytes. It also prints the return value of lseek().
Date        : 20th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc 10.c
    $ ./a.out samplefile.txt
    Return Value of lseek(New offset): 20

    $ od -c samplefile.txt
    0000000   h   e   l   l   o   w   o   r   l   d  \0  \0  \0  \0  \0
    0000020   h   e   l   l   o   w   o   r   l   d
    0000032
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc,char *argv[]){

	if(argc<2){
		printf("Enter the file name\n");
		return;
	}

	int fd=open(argv[1],O_CREAT|O_RDWR,0744);

	char buffer[11]="helloworld";

	write(fd,buffer,10);
	int l=lseek(fd,10,SEEK_CUR);
	printf("Return Value of lseek(New offset):%d\n",l);
	write(fd,buffer,10);
}
