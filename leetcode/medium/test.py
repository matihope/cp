nums = [-84, 92, 26, 19, -7, 9, 42, -51, 8, 30, -100, -13, -38]

vals = []
for i, val0 in enumerate(nums):
    for j, val1 in enumerate(nums[i + 1 :]):
        for k, val2 in enumerate(nums[j + 1 :]):
            vals.append((val0, val1, val2, val0 + val1 + val2))

vals.sort(key=lambda x: x[3])

for val in vals:
    print(val)
