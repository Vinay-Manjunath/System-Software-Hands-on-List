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
