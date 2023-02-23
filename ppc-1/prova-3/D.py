from itertools import combinations

m, n = map(int, input().split())
male = 0

b = {}
a = set()

for i in range(m):
    name, gender = input().split()
    b[name] = gender

    if gender == "M":
        male += 1

    a.add(name)

if male < 2 or m - male < 2:
    print(0)
else:
    c = 0
    li = []

    comb = list(combinations(a, n))

    for i in comb:
        male = 0

        for j in i:
            if b[j] == "M":
                male += 1
        
        if male >= 2 and n - male >= 2:
            c += 1
            li.append(",".join(sorted(i)))
    
    print(c)
    print("\n".join(sorted(li)))