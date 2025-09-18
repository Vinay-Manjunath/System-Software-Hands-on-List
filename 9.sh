#! /bin/bash

echo "inode number:" $(ls -i $1 | awk '{print $1}')
echo "Number of hard links:" $(ls -l $1 | awk '{print $2}')
echo "User ID:" $(ls -l $1 | awk '{print $3}')
echo "Group ID:" $(ls -l $1 | awk '{print $4}')
echo "Size:" $(ls -hl $1 | awk '{print $5}')
