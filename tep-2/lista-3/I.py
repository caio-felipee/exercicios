def solve(a, b):
    for i in range(2, 37, 1):
        for j in range(2, 37, 1):
            try:
                if int(a, i) == int(b, j):
                    print(f"{a} (base {i}) = {b} (base {j})")
                    return
            except:
                pass
    
    print(f"{a} is not equal to {b} in any base 2..36")

while True:
    try:
        a, b = list(input().split())
        
        solve(a, b)

    except EOFError:
        break
