#!/bin/python3

import sys
import random
import os

try:
    random.seed(int(sys.argv[1]))
except IndexError:
    random.seed(1)

n = 1000000
with open("INPUT.txt", "w") as file:
    file.write(f"{n - 1}\n")
    file.write(" ".join([str(u) for u in range(2, n + 1)]))
os.system(f'./build/dzi < INPUT.txt > OUTPUT.txt')
