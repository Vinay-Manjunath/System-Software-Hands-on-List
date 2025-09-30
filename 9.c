/*
============================================================================
Name        : 9.c
Author      : M Vinay
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 9.c
    $ ./a.out
    Press Ctrl+C. SIGINT is ignored...
    ^C^C^C^C^C^C^CNow SIGINT restored to default action.
    ^C
============================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){
	printf("Press Ctrl+C. SIGINT is ignored...\n");

	signal(SIGINT,SIG_IGN);
	sleep(5);

	printf("Now SIGINT restored to default action.\n");

	signal(SIGINT,SIG_DFL);

	while(1){
		sleep(1);
	}

	return 0;
}
