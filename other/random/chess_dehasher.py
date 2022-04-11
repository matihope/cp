import pprint


def dehash(n):
    tab = [[' ' for _ in range(8)] for _ in range(8)]
    pprint.pprint(tab)

n = int(input("Give me hash: "))
dehash(n)
