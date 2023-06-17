n, a, b = list(map(int, input().split()))

ans = min(n - a, b + 1)

print(ans)