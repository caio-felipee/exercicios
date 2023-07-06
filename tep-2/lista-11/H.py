n, l, r = list(map(int, input().split()))

min = [1] * (n - l + 1)
max = [1]

for i in range(1, l):
    min.append(2**i)

for i in range(1, r):
    max.append(2**i)

max.extend([2**(r - 1)] * (n - len(max)))
print(sum(min), sum(max))