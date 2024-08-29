vs = list(map(int, input().split()))

print("S" if all(abs(x - 1) <= 1 for x in vs) else "F")
