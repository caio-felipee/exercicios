m, n = [int(x) for x in input().split()]
revenue = 0
vmin = 0

l = map(int, input().split())

for i in l:
    revenue += i
    vmin = min(revenue, vmin)

if vmin < 0 and abs(vmin) > m:
    print(-1)
else:
    print(abs(vmin))