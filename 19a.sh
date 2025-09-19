#!/bin/bash

rm -f mknod_fifo

mknod mknod_fifo p

ls -l mknod_fifo
file mknod_fifo
