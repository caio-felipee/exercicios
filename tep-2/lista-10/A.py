from itertools import permutations

values = list(permutations(map(int, input().split())))
ans = 100000

for p in values:
    ans = min(ans, abs(p[1] - p[0]) + abs(p[2] - p[1]))

print(ans)