#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int fd[2];
	pipe(fd);

	if(fork()==0){
		close(fd[0]);
		close(1);
		dup(fd[1]);
		close(fd[1]);
		execlp("ls","ls","-l",NULL);

}
