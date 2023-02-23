N, M = [int(x) for x in input().split()]

connected_cities = []

for x in range(N):
    connected_cities.append(0)

for _ in range(M):
    for city in input().split():
        connected_cities[int(city) - 1] = connected_cities[int(city) - 1] + 1

for city in connected_cities:
    print(city)