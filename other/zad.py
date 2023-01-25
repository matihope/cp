s = 0
m = -1000
for i in range(10000):
    a = (-1)**i * 1 / (3 + (-1)**i)**i
    m = max(a, m)
    s += a

print(m, s)
