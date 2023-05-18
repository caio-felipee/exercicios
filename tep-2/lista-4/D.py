while True:
    try:
        n, b = map(int, input().split())

        sn = (2*(2**b - 1)) + 1

        print("yes" if sn >= n else "no")
        
    except EOFError:
        break