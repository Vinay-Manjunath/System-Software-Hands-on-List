/*
============================================================================
Name        : 34a.c
Author      : M Vinay
Description : Write a program to create a concurrent server.
a. use fork
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 34a.c -o fork_server
    $ ./fork_server
    Concurrent Server started...    
    Message from Client:Hello world

    Message from Client:Hi How are you
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int main() {
    struct sockaddr_in serv, cli;
    int sd, nsd, sz;
    char buf[1024];

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) exit(1);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5055);

    bind(sd, (struct sockaddr *)&serv, sizeof(serv));

    listen(sd, 5);
    printf("Concurrent Server started...\n");

    while (1) {
        sz = sizeof(cli);
        nsd = accept(sd, (struct sockaddr *)&cli, (socklen_t *)&sz);
        if (nsd < 0) { perror("accept"); continue; }

        if (fork() == 0) {
		close(sd);
		while(1){
			memset(buf, 0, sizeof(buf));
     		    	int n = read(nsd, buf, sizeof(buf));
            		if (n <= 0) break;
        		printf("Message from client: %s\n", buf);
        		write(nsd, "ACK from Server", strlen("ACK from Server") + 1);
    		}
		close(nsd);
		exit(0);
	}
	else{
		close(nsd);
	}
    }
    close(sd);
    return 0;
}
