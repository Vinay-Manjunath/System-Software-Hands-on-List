/*
============================================================================
Name        : 5.c
Author      : M Vinay
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
$ cc 5.c
$ ./a.out
   
a. Max length of arguments to exec(): 2097152 bytes
b. Max processes per user: soft = 15097, hard = 15097
c. Clock ticks per second: 100
d. Max open files: soft = 10240, hard = 1048576
e. Page size: 4096 bytes
f. Total pages in physical memory: 968761
g. Available pages in physical memory: 838561
============================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    long arg_max = sysconf(_SC_ARG_MAX);
    if(arg_max != -1)
        printf("a. Max length of arguments to exec(): %ld bytes\n", arg_max);
    else
        printf("a. Max length of arguments to exec(): Not available\n");

    if(getrlimit(RLIMIT_NPROC, &limit) == 0)
        printf("b. Max processes per user: soft = %lu, hard = %lu\n",
               limit.rlim_cur, limit.rlim_max);
    else
        printf("b. Max processes per user: Not available\n");

    long ticks = sysconf(_SC_CLK_TCK);
    if(ticks != -1)
        printf("c. Clock ticks per second: %ld\n", ticks);
    else
        printf("c. Clock ticks per second: Not available\n");

    if(getrlimit(RLIMIT_NOFILE, &limit) == 0)
        printf("d. Max open files: soft = %lu, hard = %lu\n",
               limit.rlim_cur, limit.rlim_max);
    else
        printf("d. Max open files: Not available\n");

    long page_size = sysconf(_SC_PAGESIZE);
    if(page_size != -1)
        printf("e. Page size: %ld bytes\n", page_size);
    else
        printf("e. Page size: Not available\n");

    long total_pages = sysconf(_SC_PHYS_PAGES);
    if(total_pages != -1)
        printf("f. Total pages in physical memory: %ld\n", total_pages);
    else
        printf("f. Total pages in physical memory: Not available\n");

    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    if(avail_pages != -1)
        printf("g. Available pages in physical memory: %ld\n", avail_pages);
    else
        printf("g. Available pages in physical memory: Not available\n");

    return 0;
}

