#!/bin/sh
# A simple program which calulates factorial of a number from standard input.

num=$1
fact=1
for (( i=1; i<=$num; i++ )) do
    fact=$(( fact * i ))
done
echo $fact
