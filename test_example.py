import sys
import random

try:
    random.seed(int(sys.argv[1]))
except IndexError:
    random.seed(1)

arr = []
inputs = []
answers = []
for i in range(random.randint(5, 6)):
    arr.append(0)

tree_size = len(arr)


def add_on_range(a, b, val):
    for i in range(a, b):
        arr[i] += val


def set_on_range(a, b, val):
    for i in range(a, b):
        arr[i] = val


def add_queries_for_all():
    # query for every element
    for i in range(len(arr)):
        for j in range(i + 1, len(arr) + 1):
            if random.choice([1, 2, 3, 4, 5]) == 5:
                inputs.append([3, i, j])
                answers.append(sum(arr[i:j]))


# generate changes for the tree
for i in range(2):
    op = random.choice([1, 2])
    start = random.randint(0, tree_size - 2)
    stop = random.randint(start + 1, tree_size)
    val = random.randint(1, 100)
    inputs.append([op, start, stop, val])
    set_on_range(start, stop, val) if op == 1 else add_on_range(start, stop, val)
    add_queries_for_all()


# save inputs to the file
with open('INPUT.txt', 'w') as f:
    f.write(f'{len(arr)} {len(inputs)}\n')
    for q in inputs:
        f.write(' '.join([str(x) for x in q]) + '\n')

# save outputs to the file
with open('OUTPUT.txt', 'w') as f:
    f.write('\n'.join([str(x) for x in answers]))
