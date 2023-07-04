from string import ascii_uppercase

n = int(input())
s = input()
ans = ""

for v in s:
    ans += ascii_uppercase[(ascii_uppercase.index(v) + n) % len(ascii_uppercase)]

print(ans)