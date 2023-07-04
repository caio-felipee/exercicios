n = int(input())
values = list(map(int, input().split()))
max_value = max(values)
expenses = 0

for v in values:
    expenses += (max_value - v)

print(expenses)