from math import isqrt

def is_prime(n):
    if n <= 3:
        return n > 1
    
    if n % 2 == 0 or n % 3 == 0:
        return False
    
    for i in range(5, isqrt(n) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    
    return True

n = int(input())
ans = []
i = 1

while len(ans) < n:
    x = (i * 5) + 1

    if is_prime(x):
        ans.append(str(x))
    
    i += 1

print(" ".join(ans))