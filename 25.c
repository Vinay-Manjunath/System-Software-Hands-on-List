/*
============================================================================
Name        : 25.c
Author      : M Vinay
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 25.c
    $ ./a.out
    Message Queue Info
    Access Permissions: 666
    UID: 0, GID: 0
    Time of last msg sent: Thu Jan  1 05:30:00 1970
    Time of last msg received: Thu Jan  1 05:30:00 1970
    Time of last change: Sun Sep 21 19:36:51 2025
    Size of the queue: 0
    Number of messages in queue: 0
    Maximum number of bytes allowed: 16384
    PID of last msgsnd: 0
    PID of last msgrcv: 0
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds msginfo;

    key = ftok("msgfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    if (msgctl(msgid, IPC_STAT, &msginfo) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message Queue Info\n");
    printf("Access Permissions: %o\n", msginfo.msg_perm.mode & 0777);
    printf("UID: %d, GID: %d\n", msginfo.msg_perm.uid, msginfo.msg_perm.gid);
    printf("Time of last msg sent: %s", ctime(&msginfo.msg_stime));
    printf("Time of last msg received: %s", ctime(&msginfo.msg_rtime));
    printf("Time of last change: %s", ctime(&msginfo.msg_ctime));
    printf("Size of the queue: %lu\n", msginfo.__msg_cbytes);
    printf("Number of messages in queue: %lu\n", msginfo.msg_qnum);
    printf("Maximum number of bytes allowed: %lu\n", msginfo.msg_qbytes);
    printf("PID of last msgsnd: %d\n", msginfo.msg_lspid);
    printf("PID of last msgrcv: %d\n", msginfo.msg_lrpid);

    return 0;
}

