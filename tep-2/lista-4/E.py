# k^n = p
# what is the value of k?

def binary_search(n, p, l, r):
    mid = int((l + r) / 2)
    val = mid**n

    if val == p:
        return mid
    elif val > p:
        return binary_search(n, p, l, mid - 1)
    else:
        return binary_search(n, p, mid + 1, r)

interval = [1, 10**9]

while True:
    try:
        n = int(input())
        p = int(input())

        print(binary_search(n, p, interval[0], interval[1]))

    except EOFError:
        break
