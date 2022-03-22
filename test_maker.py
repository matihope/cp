#!/bin/python3

import sys
import random
import os

try:
    random.seed(int(sys.argv[1]))
except IndexError:
    random.seed(6)

n = 1

with open('INPUT.txt', 'w') as f:
    f.write(f'{random.randint(1, 25000)} ')
    f.write(f'{random.randint(1, 25000)}\n')


os.system('./build/nwd < INPUT.txt > OUTPUT.txt')
