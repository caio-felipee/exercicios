queries = int(input())
sleeping = []

for _ in range(queries):
    command = input()

    if(command == "Kick"):
        if(len(sleeping) > 0):
            sleeping.pop()
        else:
            continue

    elif(command == "Test"):
        if(len(sleeping) > 0):
            print(sleeping[-1])
        else:
            print("Not in a dream")
    
    elif(command.startswith("Sleep")):
        k, v = command.split()

        sleeping.append(v)