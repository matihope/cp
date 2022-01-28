import math

for angle in range(1, 45000, 1):
    angle /= 1000
    a = 10000
    y = 0
    for i in range(13):
        y = math.tan(math.radians(angle)) * (a - y)
        if round(y, 1) == 0 or round(y, 1) == a:
            print(f"Found {angle}")
    print(y)
