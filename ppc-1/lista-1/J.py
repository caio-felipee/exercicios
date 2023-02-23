from math import floor

def shortest(a):
    return a[0]

tests_number = int(input())

for _ in range(tests_number):
    streets, avenues, friends = list(map(int, input().split()))
    index = floor((friends - 1) / 2)

    friends_location = []

    for __ in range(friends):
        loc = list(map(int, input().split()))
        friends_location.append(loc)

    friends_location.sort(key = shortest)
    best_grid = friends_location[index]

    print(f"(Street: {best_grid[0]}, Avenue: {best_grid[1]})")