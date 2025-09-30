/*
============================================================================
Name        : 4.c
Author      : M Vinay
Description : Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter.
Date        : 21st Sept, 2025
============================================================================
Sample Execution:
    $ cc 4.c
    $ ./a.out
    CPU cycles taken by 100 getpid(): 29063
============================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static __inline__ uint64_t rdtsc(void)
{
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;

    start = rdtsc();

    for(int i=0;i<100;i++)
    	getpid();

    end = rdtsc();

    printf("CPU cycles taken by 100 getpid(): %lu\n", (end - start));


    return 0;
}
