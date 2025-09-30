/*
============================================================================
Name        : 34b.c
Author      : M Vinay
Description : Write a program to create a concurrent server.
a. use pthread
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 34b.c -o fork_server
    $ ./pthread_server
    Concurrent Server (pthread) started...
    Message from Client:Hello world

    Message from Client:Hi How are you
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

void *handle_client(void *arg) {
    int nsd = *(int *)arg;
    free(arg);
    char buf[1024];

    while (1) {
        memset(buf, 0, sizeof(buf));
        int n = read(nsd, buf, sizeof(buf));
        if (n <= 0) break;
        printf("Message from client: %s\n", buf);
        write(nsd, "ACK from Server", strlen("ACK from Server") + 1);
    }
    close(nsd);
    return NULL;
}

int main() {
    struct sockaddr_in serv, cli;
    int sd, nsd, sz;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) { perror("socket"); exit(1); }

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5055);

    if (bind(sd, (struct sockaddr *)&serv, sizeof(serv)) < 0) {
        perror("bind"); exit(1);
    }

    listen(sd, 5);
    printf("Concurrent Server (pthread) started...\n");

    while (1) {
        sz = sizeof(cli);
        nsd = accept(sd, (struct sockaddr *)&cli, (socklen_t *)&sz);
        if (nsd < 0) { perror("accept"); continue; }

        pthread_t tid;
        int *pclient = malloc(sizeof(int));
        *pclient = nsd;
        pthread_create(&tid, NULL, handle_client, pclient);
        pthread_detach(tid);
    }

    close(sd);
    return 0;
}
