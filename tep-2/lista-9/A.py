goal = int(input())
coins = int(input())

rest = goal % 500

print("Yes" if coins >= rest else "No")