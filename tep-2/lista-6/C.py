n = int(input())
s = 2 * n
is_prime = [True for _ in range(s + 1)]

def solve():
    for i in range(n, s, 1):
        if is_prime[i]:
            return i

def get_primes():
    p = 2

    while p * p <= s:
        if is_prime[p]:
            for i in range(p * p, s + 1, p):
                is_prime[i] = False

        p += 1

get_primes()
print(solve())