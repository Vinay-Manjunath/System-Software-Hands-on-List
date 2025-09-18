/*
============================================================================
Name        : 17b.c
Author      : M Vinay
Description : Simulates ticket reservation. Implements write lock on ticket.txt, reads the current ticket number, increments it, writes back, and prints the new ticket number.
Date        : 1st Sept, 2025
Sample Output:
    $ ./a.out
    Counter updated to 1001
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
	int fd=open("ticket.txt",O_RDWR,0744);

	struct flock lock;

	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();

	//printf("Before entering the critical section\n");

	char buffer[10];

	fcntl(fd,F_SETLK,&lock);

	//printf("Entered critical section\n");
	
	lseek(fd,0,SEEK_SET);
	int n=read(fd,buffer,sizeof(buffer));

	buffer[n]='\0';

	if(n==-1){
		fprintf(stderr,"Read failed\n");
		exit(1);
	}

	int c=atoi(buffer);

	c++;

	sprintf(buffer,"%d\n",c);

	ftruncate(fd, 0);
	lseek(fd,0,SEEK_SET);
	
	int n1=write(fd,buffer,n);

	if(n1==-1){
		fprintf(stderr,"Read failed\n");
                exit(1);
        }

	printf("Counter updated to %d\n",c);

	lock.l_type=F_UNLCK;

	fcntl(fd,F_SETLK,&lock);

	//printf("Exiting from critical section\n");
}
