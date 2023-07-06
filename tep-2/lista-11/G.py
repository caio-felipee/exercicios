from math import log2

n = int(input())

for _ in range(n):
    value = int(input())
    log = log2(value)

    print("NO" if log == int(log) else "YES")