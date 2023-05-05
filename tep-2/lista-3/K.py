N = int(input())

while N >= 0:
    ternary = ""

    if not N:
        ternary += "0"
        
    while N:
        ternary += str(N % 3)

        N = int(N / 3)

    print(ternary[::-1])

    N = int(input())