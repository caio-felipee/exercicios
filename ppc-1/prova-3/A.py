from itertools import permutations

b = input().split("/")
a = []

for i in b:
    for j in i:
        a.append(j)

print(len(set(permutations(a))))