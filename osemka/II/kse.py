n = int(input().rstrip())
times = 0
m = {}
for i in input().rstrip().split(' '):
    i = int(i)
    if m.get(i):
        m[i] += 1
    else:
        m[i] = 1
    times = max(times, m[i])

ile = 0
while times < n:
    ile += 1
    x = min(n - times, times)
    ile += x
    times += x
print(ile)
