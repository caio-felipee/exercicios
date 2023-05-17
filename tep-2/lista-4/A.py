X = int(input())

highest = 1

for i in range(1, 1001, 1):
    if i >= X:
        break

    for j in range(2, 1001, 1):
        n = i**j

        if n > X:
            break

        highest = max(n, highest)

print(highest)