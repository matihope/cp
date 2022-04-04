import random

# nums = [21, 26, 31, 36, 41, 46, 51, 56, 61, 66, 71, 76, 81]
nums = [21, 26, 31, 36, 41, 46, 51, 56, 61]
xs = []

while True:
    while True:
        random.shuffle(nums)
        good = True
        for i in range(3):
            if sum(nums[i:i+7]) % 3 != 0:
                good = False
                break
        if good:
            break

    x = ""
    for num in nums:
        if num % 3 == 0:
            x += '0 '
        elif num % 3 == 1:
            x += '2 '
        elif num % 3 == 2:
            x += '1 '
    # print(x)
    if x not in xs:
        xs.append(x)
    print(len(xs))

