#!/bin/python3

import sys
import random
import os

try:
    random.seed(int(sys.argv[1]))
except IndexError:
    random.seed(6)

n = 10000

with open('INPUT.txt', 'w') as f:
    f.write('1\n')
    f.write(f'9 {n}\n')
    f.write('1 2\n2 3\n2 4\n4 5\n1 6\n6 8\n6 7\n1 9\n')
    for _ in range(n):
        op = random.choice([1, 2])
        x = random.randint(1, 9)
        if op == 1:
            f.write(f'{op} {x} {random.randint(1, 15)}\n')
        else:
            f.write(f'{op} {x}\n')

os.system('./build/dro < INPUT.txt > OUTPUT.txt')
