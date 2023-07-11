n = int(input())
ans = 0

if n % 2 == 0:
    ans = (n // 4) - (1 if n % 4 == 0 else 0)

print(ans)