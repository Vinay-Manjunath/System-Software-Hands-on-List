/*
============================================================================
Name        : 19e.c
Author      : M Vinay
Description : Create a FIFO using the mkfifo() system call.
Date        : 30th Sept, 2025
============================================================================
Sample Execution:
$ gcc 19e.c -o 19e
$ ./19e
FIFO created using mkfifo() syscall: mkfifo_fifo
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc,char *argv[]){

        char *fifo="mkfifo_fifo";

        if(mkfifo(fifo,0666)==-1){
                fprintf(stderr,"Error creating fifo\n");
                return 1;
        }
        printf("FIFO created using mkfifo() syscall:%s\n",fifo);
        return 0;
}
