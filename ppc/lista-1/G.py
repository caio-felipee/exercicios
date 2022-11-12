names_quantity = int(input())
names = input().split()
tries = int(input())

for _ in range(tries):
    index = int(input()) - 1

    options = []
    best_option = {
        "names": [],
        "distance": [],
        "abs_distance": []
    }

    if names[index] != "?":
        print(names[index])
        continue

    for i in range(names_quantity):
        if names[i] != "?":
            options.append({ "index": i, "distance": index - i })

    for option in options:
        if abs(option["distance"]) <= max(best_option["abs_distance"], default = 999):
            if abs(option["distance"]) < max(best_option["abs_distance"], default = 999):
                best_option["distance"].clear()
                best_option["names"].clear()
                best_option["abs_distance"].clear()
            
            best_option["abs_distance"].append(abs(option["distance"]))
            best_option["distance"].append(option["distance"])
            best_option["names"].append(names[option["index"]])
    
    name = best_option["names"]
    distance = best_option["distance"]
    abs_distance = best_option["abs_distance"]

    if len(name) == 1:
        left = "left of "
        right = "right of "

        if distance[0] < 0:
            print(f"{left * abs_distance[0]}{name[0]}")
        else:
            print(f"{right * abs_distance[0]}{name[0]}")
    else:
        print(f"middle of {name[0]} and {name[1]}")
