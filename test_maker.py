#!/bin/python3

import sys
import random
import os

try:
    random.seed(int(sys.argv[1]))
except IndexError:
    random.seed(6)

s1 = ''.join([random.choice(['a', 'b']) for _ in range(4)])
s2 = ''.join([random.choice(['a', 'b']) for _ in range(6)])
with open('INPUT.txt', 'w') as f:
    f.write(s1 + ' ' + s2)

os.system('./build/pam_brut < INPUT.txt > OUTPUT.txt')
