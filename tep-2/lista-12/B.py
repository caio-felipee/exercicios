s = input()
ls = len(s)
ans = 0

for i in range(ls // 2):
    if s[i] != s[ls - i - 1]:
        ans += 1
    
print(ans)