/*
============================================================================
Name        : 19.c
Author      : M Vinay
Description : C program to measure the time taken to execute getpid() 
              system call using the CPU time stamp counter.
Date        : 5th Sept, 2025
============================================================================
Sample Execution:
    $ cc 19.c
    $ ./a.out
    getpid() returned PID: 1561
    CPU cycles taken by getpid(): 6381
============================================================================
*/

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
    pid_t pid = getpid(); 
    end = rdtsc();        

    printf("getpid() returned PID: %d\n", pid);
    printf("CPU cycles taken by getpid(): %lu\n", (end - start));
    

    return 0;
}

