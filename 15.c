#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

void main(){
	int fd[2];
	pipe(fd);
	char buf[10];

	if(!fork()){
		close(fd[0]);
		write(fd[1],"Hello\n",7);
	}
	else{
		close(fd[1]);
		read(fd[0],buf,7);
		printf("%s\n",buf);
		wait(0);
	}
}

