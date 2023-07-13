n, d = list(map(int, input().split()))
vs = list(map(int, input().split()))
ans = 0

for i in range(1, n):
    if vs[i - 1] >= vs[i]:
        t = (vs[i - 1] - vs[i]) // d + 1
        vs[i] += (t * d)
        ans += t

print(ans)