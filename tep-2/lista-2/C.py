N = int(input())

for _ in range(N):
    number = int(input())
    digits = list(0 for __ in range(10))

    for i in range(1, number + 1):
        for v in str(i):
            digits[int(v)] += 1
    
    print(" ".join(map(str, digits)))