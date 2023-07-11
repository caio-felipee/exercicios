vs = list(map(int, input().split()))

print("win" if sum(vs) <= 21 else "bust")