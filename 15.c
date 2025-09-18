/*
============================================================================
Name        : 15.c
Author      : M Vinay
Description : C program to display all environment variables of the user
              using the extern variable 'environ'.
Date        : 20th Aug, 2025
============================================================================
Sample Execution & Output:

    $ gcc 15.c
    $ ./a.out
    PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
    HOME=/root
    SHELL=/bin/bash
    USER=root
    ...
============================================================================
*/

#include <stdio.h>

extern char **environ;

void main(){
	char **env=environ;

	while(*env){
		printf("%s\n",*env);
		env++;
	}
}
