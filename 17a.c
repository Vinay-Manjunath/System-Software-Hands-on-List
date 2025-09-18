/*
============================================================================
Name        : 17a.c
Author      : M Vinay
Description : Initialize ticket file with starting ticket number (1000).
Date        : 1st Sept, 2025
Sample Output:
    $ ./a.out
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int fd;
	char buf[15];

	fd=open("ticket.txt",O_RDWR|O_CREAT|O_TRUNC,0744);

	if(fd==-1){
		fprintf(stderr,"Error opening the file\n");
		exit(1);
	}
	sprintf(buf,"%d\n",1000);

	int n=write(fd,buf,strlen(buf));
	if(n==-1){
		printf("Error writing to the file\n");
		exit(1);
	}
	close(fd);
}
