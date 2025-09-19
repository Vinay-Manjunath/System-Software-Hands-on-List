#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int main() {
    char *fifo1 = "21fifo2";
    char *fifo2 = "21fifo1";

    if (mkfifo(fifo1, 0666) == -1) perror("mkfifo fifo1");
    if (mkfifo(fifo2, 0666) == -1) perror("mkfifo fifo2");

    int fd1 = open(fifo2, O_RDWR);
    int fd2 = open(fifo1, O_RDWR);
    if (fd1 == -1 || fd2 == -1) {
        perror("open");
        return 1;
    }

    char message[100];

    while (1) {
        memset(message, 0, sizeof(message));
        read(fd1, message, sizeof(message) - 1);
        printf("Friend: %s\n", message);
        if (strcmp(message, "exit") == 0) break;

        printf("You: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';
        write(fd2, message, strlen(message) + 1);
        if (strcmp(message, "exit") == 0) break;
    }

    close(fd1);
    close(fd2);
    return 0;
}

