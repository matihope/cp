import random


def f(x):
    return x - 2/x


print("Workin...")
i = input("GIMME: ")
for _ in range(100000):
    x = random.randint(-1000, 1000)
    if x == 0:
        continue
    if type(f(x)) == int:
        print(x)
