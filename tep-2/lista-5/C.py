from math import gcd

while True:
    l = list(map(int, input().split()))

    if len(l) < 2 and not l[0]:
        break

    l.pop()

    v = list(zip(l, l[1::]))

    print(gcd(*[abs(i[0] - i[1]) for i in v]))