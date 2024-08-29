n = int(input())
vs = input()

i, a = 0, 0
ans = 0
while i < n:
    if vs[i] == 'a':
        a += 1
    else:
        if a > 1:
            ans += a
        a = 0
    i += 1

if a > 1:
    ans += a
print(ans)
