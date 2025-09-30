/*
============================================================================
Name        : 18.c
Author      : M Vinay
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
$ cc 18.c
$ ./a.out
     1       9      47
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
        int fd1[2],fd2[2];
        pipe(fd1);
	pipe(fd2);

        if(fork()==0){
                close(fd1[0]);
                dup2(fd1[1],1);
                close(fd1[1]);
                execlp("ls","ls","-l",NULL);
        }
        else{
		if(fork()==0){
                	close(fd1[1]);
                	dup2(fd1[0],0);
                	close(fd1[0]);
			close(fd2[0]);
			dup2(fd2[1],1);
			close(fd2[1]);
                	execlp("grep","grep","^d",NULL);
		}
		else{
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[1]);
                	dup2(fd2[0],0);
                	close(fd2[0]);
                	execlp("wc","wc",NULL);
		}
        }
}
