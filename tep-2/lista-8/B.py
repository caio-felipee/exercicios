a, b, c, k = list(map(int, input().split()))

ans = min(k, a)

k -= a

if k > 0:
    k -= b

if k > 0:
    ans += (k * -1)

print(ans)