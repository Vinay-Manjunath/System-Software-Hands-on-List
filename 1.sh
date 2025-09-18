#!/bin/bash

#============================================================================
#Name        : 1.sh
#Author      : M Vinay
#Description : Shell script to create different types of files:
#                a. Soft link
#                b. Hard link
#                c. FIFO special file
#Date        : 14th Aug, 2025
#============================================================================
#Sample Output:
#    $ ./1.sh
#    test_file test_file_hrdlink test_file_sftlink
#
#    $ ls -l test_file test_file_hrdlink test_file_sftlink
#    -rw-r--r-- 2 root root 0 Aug 14 22:34 test_file
#    -rw-r--r-- 2 root root 0 Aug 14 22:34 test_file_hrdlink
#    lrwxrwxrwx 1 root root 9 Aug 14 22:34 test_file_sftlink -> test_file
#============================================================================

rm -f test_file test_file_sftlink test_file_hrdlink myfifo
touch test_file
ln -s test_file test_file_sftlink
ln test_file test_file_hrdlink
mkfifo myfifo

ls test_file test_file_sftlink test_file_hrdlink

