/*
============================================================================
Name        : 1.c
Author      : M Vinay
Description : C program to create different types of files using system calls:
                a. Soft link (symlink)
                b. Hard link (link)
                c. FIFO special file (mkfifo)
Date        : 14th Aug, 2025
============================================================================
Sample Output:
    $ gcc 1.c -o 1.out
    $ ./1.out test_file
    Soft link created
    Hard link created
    Fifo file created

    $ ls -l test_file hardlink.txt softlink.txt myfifo
    -rw-r--r-- 1 root root 0 Aug 14 22:30 test_file
    -rw-r--r-- 2 root root 0 Aug 14 22:30 hardlink.txt
    lrwxrwxrwx 1 root root 9 Aug 14 22:30 softlink.txt -> test_file
    prw-r--r-- 1 root root 0 Aug 14 22:30 myfifo
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Enter the original file\n");
        exit(1);
    }

    if (symlink(argv[1], "softlink.txt") == -1) {
        fprintf(stderr, "Error creating the softlink\n");
    } else {
        printf("Soft link created\n");
    }

    if (link(argv[1], "hardlink.txt") == -1) {
        fprintf(stderr, "Error creating the hardlink\n");
    } else {
        printf("Hard link created\n");
    }

    if (mkfifo("myfifo", 0666) == -1) {
        fprintf(stderr, "Error creating the fifo file\n");
    } else {
        printf("Fifo file created\n");
    }

    return 0;
}

