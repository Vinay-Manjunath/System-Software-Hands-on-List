#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void main(){
	int fd[2];

	pipe(fd);
	char buf[10];

	getchar();
	write(fd[1],"Hello\n",7);
	read(fd[0],buf,7);

	printf("%s\n",buf);
}

