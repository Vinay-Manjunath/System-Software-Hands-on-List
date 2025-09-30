#!/bin/bash

: '
============================================================================
Name        : 19b.sh
Author      : M Vinay
Description : Create a FIFO file using mkfifo command and display its details.
Date        : 30th Sept, 2025
============================================================================
Sample Execution:
$ ./19b.sh
p--------- 1 vinay users 0 Sep 30 19:45 mkfifo_fifo
mkfifo_fifo: fifo
============================================================================
'

rm -f mkfifo_fifo

mkfifo mkfifo_fifo p

ls -l mkfifo_fifo
file mkfifo_fifo
