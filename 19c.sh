#!/bin/bash

rm -f fifo1 fifo2

strace -o log1 mknod fifo1 p 2>/dev/null
strace -o log2 mkfifo fifo2 2>/dev/null

echo "System call counts:"
echo -n "mknod  : "
wc -l < log1
echo -n "mkfifo : "
wc -l < log2

rm -f log1 log2

