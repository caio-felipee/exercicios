n = input()
i = 0
r = len(n) - 1

while(i < r and n[i] == n[r]):
    i += 1
    r -= 1

if(n[i] == n[r]):
    print("Yes")
else:
    print("No")