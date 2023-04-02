baby, adult, king = map(int, input().split())
max_capacity, enemies = map(int, input().split())
order = input()

get_type = {
    "R": king,
    "A": adult,
    "F": baby
}

status = [0]
i = 0
index = 0

while(i < enemies):
    mg = get_type[order[i]]

    if(len(status) < index + 1): 
        status.append(0)

    if(status[index] + mg > max_capacity):
        index += 1
        continue
    else:
        status[index] += mg
        index = 0
        i += 1

print(len(status))