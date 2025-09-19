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
