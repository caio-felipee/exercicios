n = int(input())
ni = list(map(int, input().split()))
l, r = 0, n - 1

n /= 2
v = 0
c = ""

while n:
    if ni[l] > ni[r]:
        v += ni[l]
        c += "L"
        l += 1
    elif ni[l] < ni[r]:
        v += ni[r]
        c += "R"
        r -= 1
    else:
        li, ri = l, r
        while li < ri and ni[li] == ni[ri]:
            li += 1
            ri -= 1

        if(ni[li] >= ni[ri]):
            v += ni[l]
            c += "L"
            l += 1
        else:
            v += ni[r]
            c += "R"
            r -= 1
    
    n -= 1

print(v)
print(c)