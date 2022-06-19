#!/bin/python3

import sys
import random
import os

try:
    random.seed(int(sys.argv[1]))
except IndexError:
    random.seed(1)

n = 5
max_s = 100
for _ in range(n):
    x1 = random.randint(1, max_s)
    y1 = random.randint(1, max_s)
    x2 = random.randint(x1, max_s)
    y2 = random.randint(y1, max_s)
    print(x1, y1, x2 - x1 + 1, y2 - y1 + 1)
