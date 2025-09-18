/*
============================================================================
Name        : 18b.c
Author      : M Vinay
Description : C program to implement a read lock on a record in a file.
Date        : 1st Sept, 2025
============================================================================
Sample Execution:
    $ cc 18b.c -o 18b
    $ ./18b 2
    Record 2 locked for reading.
    Content: Record 2 modified by PID 4321
    Record 2 unlocked.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define RECORD_SIZE 50
#define FILENAME "records.txt"

void main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <record_number (1-3)>\n", argv[0]);
        exit(1);
    }

    int rec_no = atoi(argv[1]);
    if (rec_no < 1 || rec_no > 3) {
        fprintf(stderr, "Record number must be between 1 and 3\n");
        exit(1);
    }

    int fd = open(FILENAME, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (rec_no - 1) * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    printf("Before entering critical section:\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - locking");
        exit(1);
    }

    printf("Record %d locked for reading.\n", rec_no);
    getchar();

    lseek(fd, (rec_no - 1) * RECORD_SIZE, SEEK_SET);
    char buffer[RECORD_SIZE + 1];
    int bytes = read(fd, buffer, RECORD_SIZE);
    buffer[bytes] = '\0';
    printf("Content: %s\n", buffer);

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - unlocking");
        exit(1);
    }

    printf("Record %d unlocked.\n", rec_no);
    close(fd);
}

