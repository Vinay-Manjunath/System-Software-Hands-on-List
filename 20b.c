#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
	char *fifo="20fifo";

	mkfifo(fifo,0666);

	int fd=open(fifo,O_RDONLY);
	if(fd==-1){
		fprintf(stderr,"Error opening the fifo\n");
		return 1;
	}

	char buffer[100];
	read(fd,buffer,sizeof(buffer));
	printf("Message received from FIFO:%s\n",buffer);

	close(fd);
	return 0;
}
