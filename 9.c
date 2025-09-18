/*
============================================================================
Name        : 9.c
Author      : M Vinay
Description : C program to print various information about a given file
              including inode, number of hard links, uid, gid, size, block
              size, number of blocks, and times of last access, modification,
              and status change using stat() system call.
Date        : 20th Aug, 2025
============================================================================
Sample Execution & Output:

    $ cc 9.c 
    $ ./a.out 9.c
    Inode Number: 20310
    Number of hard links: 1
    Uid: 0
    Gid: 0
    Size: 1024 bytes
    Block Size: 4096
    Number of Blocks: 8
    Last Access Time: Sun Aug 20 01:17:14 2025
    Last Modification Time: Sun Aug 20 01:17:13 2025
    Last Change Time: Sun Aug 20 01:17:14 2025
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

void main(int argc,char *argv[]){
	struct stat filestat;

	if(argc != 2) {
        	fprintf(stderr, "Enter the filename\n");
        	return;
    	}

	if(stat(argv[1],&filestat)<0){
		return;
	}

	printf("Inode Number:%ld\n",filestat.st_ino);
	printf("Number of hard links:%ld\n",filestat.st_nlink);
	printf("Uid:%d\n",filestat.st_uid);
	printf("Gid:%d\n",filestat.st_gid);
	printf("Block Size:%ld\n",filestat.st_blksize);
	printf("Number of blocks:%ld\n",filestat.st_blocks);
	printf("Last Access Time:%s\n",ctime(&filestat.st_atime));
	printf("Last Modification Time:%s\n",ctime(&filestat.st_mtime));
	printf("Last change Time:%s\n",ctime(&filestat.st_ctime));
}
