n = int(input())

for _ in range(n):
    a, b = list(map(int, input().split()))
    amount = 0

    if a > b:
        a, b = b, a

    while a != b:
        value = (b - a)

        if b - a > 10:
            amount += value//10
            a += (value//10)*10
        else:
            a += value
            amount += 1
    
    print(amount)