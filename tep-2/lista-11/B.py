n = int(input())
s = input()

s1 = s[:(n//2)]
s2 = s[(n//2):]

print("Yes" if s1 == s2 else "No")