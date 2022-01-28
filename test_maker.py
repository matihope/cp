import sys
import random
import os

try:
    random.seed(int(sys.argv[1]))
except IndexError:
    random.seed(1)

class Vert:
    def __init__(self, conns, edge_to_me):
        self.conns = []
        self.visited = False
        self.edge_to_me = 0
        self.dist = 0
        self.p = 0

graph = [vert for i in range(9)]

graph = [
    None,
    Vert([3, 2], 0),
    Vert([1], 6),
    Vert([1, 4, 6], 2),
    Vert([3, 7, 5], 15),
    Vert([4], 4),
    Vert([3, 8], 7),
    Vert([4], 8),
    Vert([6], 5),
]

def dfs(start):
    for vert in graph:
        if vert != None:
            vert.visited = False
            
    def _dfs(v)
        v.visited = True
        for ch in v.conns:
            ch.dist = v.dist + ch.edge_to_me
            ch.p = v
            _dfs(ch)
            
dfs(graph[1])

def bfs(v):
    for vert in graph:
        if vert != None:
            vert.visited = False
    st = [v]
    graph[v].visited = True
            
    while len(st):
        
    
    

base = """8
1 3 2
1 2 6
3 4 15
3 6 7
4 5 4
4 7 8
6 8 5
"""
inpt = []
for _ in range(16):
    op = random.choice(['*', '?'])
    if op == '*':
        a = random.randint(2, 8)
        c = random.randint(1, 20)
        inpt.append([op, a, graph[a].p, c])
        graph[a].edge_to_me = c
    else:
        a = random.randint(1, 8)
        b = random.randint(1, 8)
        inpt.append([op, a, b])
        dfs(1)
        outpt
    
