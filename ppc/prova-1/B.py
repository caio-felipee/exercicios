cards = []
value = 0

for _ in range(4):
    for x in input().split():
        cards.append(x)

for card in cards:
    val = 0

    if not card[0].isnumeric():
        if card[0] == "A":
            val = 1
        else:
            val = 10
    else:
         val = int(card[0])
    
    if val + value > 21:
        break
    else:
        value += val

print(value)