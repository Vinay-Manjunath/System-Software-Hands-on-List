/*
============================================================================
Name        : 8.c
Author      : M Vinay
Description : C program to open a file in read-only mode, read it line by
              line using read() system call, and display each line on STDOUT.
Date        : 16th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc 9.c
    $ ./a.out sample.txt
    Hello, this is line 1
    This is line 2
    End of file reached
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void main(int argc,char *argv[]){
	
	if(argc!=2){
		fprintf(stderr,"Enter the file name\n");
		return;
	}

	int fd=open(argv[1],O_RDONLY);

	if(fd==-1){
		printf("Invalid file\n");
		return;
	}

	char buffer[2];
	char res[1024]="";

	while(1){
		int r=read(fd,buffer,1);
		if(r==0){
			close(fd);
			break;
		}
		buffer[1]='\0';
		if(buffer[0]=='\n'){
			getchar();
			printf("%s",res);
			res[0]='\0';
		}
		else{
			strcat(res,buffer);
		}
	}	
	printf("\n");	
}
