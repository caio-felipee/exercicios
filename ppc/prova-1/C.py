num = int(input())
wines = []

for _ in range(num):
    words = input().split()

    if(words[0] == "?"):
        if(not len(wines)):
            print(-1)
            continue
        
        wines.sort()
        print(wines[0])
        wines.pop(0)
        continue
    
    if(words[0] == "+"):
        wines.append(int(words[1]))