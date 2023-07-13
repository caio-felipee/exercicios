a, b, k = list(map(int, input().split()))
a -= k

if a < 0:
    b += a

print(f"{a if a >= 0 else 0} {b if b >= 0 else 0}")