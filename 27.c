/*
============================================================================
Name : 27.c
Author : M Vinay
Date : 05-09-2025
Description : 
    Write a program to execute `ls -Rl` using the following exec family calls:
    a. execl 
    b. execlp 
    c. execle 
    d. execv 
    e. execvp 

    Each child process demonstrates one variant of exec.
============================================================================
Sample Output:
    $ cc 27.c -o exec_ls
    $ ./exec_ls

    Using execl
    .:
    total 20
    -rw-r--r-- 1 root root  123 Sep  1 10:20 23.c
    -rw-r--r-- 1 root root  456 Sep  1 10:21 24.c
    drwxr-xr-x 2 root root 4096 Sep  1 10:22 dir1

    Using execlp
    .:
    total 20
    -rw-r--r-- 1 root root  123 Sep  1 10:20 23.c
    -rw-r--r-- 1 root root  456 Sep  1 10:21 24.c
    drwxr-xr-x 2 root root 4096 Sep  1 10:22 dir1

    Using execle
    .:
    total 20
    -rw-r--r-- 1 root root  123 Sep  1 10:20 23.c
    -rw-r--r-- 1 root root  456 Sep  1 10:21 24.c
    drwxr-xr-x 2 root root 4096 Sep  1 10:22 dir1

    Using execv
    .:
    total 20
    -rw-r--r-- 1 root root  123 Sep  1 10:20 23.c
    -rw-r--r-- 1 root root  456 Sep  1 10:21 24.c
    drwxr-xr-x 2 root root 4096 Sep  1 10:22 dir1

    Using execvp
    .:
    total 20
    -rw-r--r-- 1 root root  123 Sep  1 10:20 23.c
    -rw-r--r-- 1 root root  456 Sep  1 10:21 24.c
    drwxr-xr-x 2 root root 4096 Sep  1 10:22 dir1
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
	pid_t pid;
	int status;

	pid=fork();
	if(pid==0){
		printf("Using execl\n");
		execl("/bin/ls","ls","-Rl",NULL);
		fprintf(stderr,"execl failed\n");
		exit(1);
	}
	waitpid(pid,&status,0);

	pid=fork();
        if(pid==0){
                printf("\nUsing execlp\n");
                execlp("ls","ls","-Rl",NULL);
                fprintf(stderr,"execlp failed\n");
                exit(1);
        }
        waitpid(pid,&status,0);

	pid=fork();
        if(pid==0){
                printf("\nUsing execle\n");
		char *envp[]={"PATH=/usr/bin",NULL};
                execle("/bin/ls","ls","-Rl",NULL,envp);
                fprintf(stderr,"execle failed\n");
                exit(1);
        }
        waitpid(pid,&status,0);

	pid=fork();
        if(pid==0){
                printf("\nUsing execv\n");
		char *args[]={"ls","-Rl",NULL};
                execv("/bin/ls",args);
                fprintf(stderr,"execc failed\n");
                exit(1);
        }
        waitpid(pid,&status,0);

	pid=fork();
        if(pid==0){
                printf("\nUsing execvp\n");
                char *args[]={"ls","-Rl",NULL};
                execvp("ls",args);
                fprintf(stderr,"execc failed\n");
                exit(1);
        }
        waitpid(pid,&status,0);

}
