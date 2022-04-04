#!/bin/python3

import sys
import random
import os

try:
    random.seed(int(sys.argv[1]))
except IndexError:
    random.seed(6)

n = 8
counter = 0
d = {i + 1: [] for i in range(n)}
for i in range(n):
    for j in range(n):
        if random.randint(1, 10) in [5, 6]:
            e = [j + 1, random.randint(1, 10)]
            if e[0] == i + 1:
                continue
            good = True
            for edges in d[e[0]]:
                if edges[0] == i + 1:
                    good = False
                    break

            if good:
                d[i + 1].append(e)
                counter += 1

# print(d)
print(n, counter)
for i in range(n):
    for j in d[i + 1]:
        print(i + 1, j[0], j[1])
