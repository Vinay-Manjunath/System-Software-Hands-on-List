#!/bin/bash

: '
============================================================================
Name        : 19a.sh
Author      : M Vinay
Description : Create a FIFO file using mknod command and display its details.
Date        : 30th Sept, 2025
============================================================================
Sample Execution:
$ ./19a.sh
p--------- 1 vinay users 0 Sep 30 19:30 mknod_fifo
mknod_fifo: fifo
============================================================================
'

rm -f mknod_fifo

mknod mknod_fifo p

ls -l mknod_fifo
file mknod_fifo
