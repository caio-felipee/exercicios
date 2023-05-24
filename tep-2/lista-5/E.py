from math import gcd

n = int(input())

for i in range(n):
    values = list(map(int, input().split()))
    ans = 0

    for v in values:
        for vv in values:
            if v != vv:
                ans = max(ans, gcd(v, vv))
    
    print(ans)