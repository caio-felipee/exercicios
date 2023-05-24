from math import log2

while True:
    n = int(input())

    if n <= 0:
        break

    print(int(log2(n)))