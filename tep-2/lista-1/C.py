a = int(input())
b = int(input())

for x in range(1, 4):
    if not x in [a, b]:
        print(x)
        break