#!/bin/python3

import sys
import random
import os

try:
    random.seed(int(sys.argv[1]))
except IndexError:
    random.seed(6)

out = ''
n, m = 8, 8
arr = [i + 1 for i in range(n)]
random.shuffle(arr)
out += f'{n} {m}\n'
for c in arr:
    out += f'{c} '
out += '\n'
outpt = []
for i in range(m):
    num = random.choice(arr)
    while num in outpt:
        num = random.choice(arr)
    outpt.append(num)
    out += f'{num}\n'

with open('INPUT.txt', 'w') as f:
    f.write(out)

os.system('./build/count_inversions < INPUT.txt > OUTPUT.txt')
