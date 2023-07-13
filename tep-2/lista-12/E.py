from itertools import cycle

n, m = list(map(int, input().split()))
circle = cycle([i for i in range(1, n + 1)])

for i in circle:
    if i > m:
        break
    
    m -= i

print(m)