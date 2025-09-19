#!/bin/bash

rm -f mkfifo_fifo

mkfifo mkfifo_fifo p

ls -l mkfifo_fifo
file mkfifo_fifo
