games, pilots = list(map(int, input().split()))

while games > 0 and pilots > 0:
    players_rank = []
    scores = []

    for _ in range(games):
        players_rank.append(list(map(int, input().split())))

    for _ in range(int(input())):
        order = list(map(int, input().split()))
        order.pop(0)

        scores.append(order)

    for score in scores:
        for game in range(games):
            player_stats = {}

            for pilot in range(pilots):
                player_stats[pilot] = 0

            for player in players_rank[game]:
                player_index = players_rank[game].index(player)

                if(player_index < len(score)):
                    player_stats[player - 1] = player_stats[player - 1] + score[player_index] 
        
            ranking = dict(sorted(player_stats.items(), key=lambda item: item[1], reverse = True))

            items = list(ranking.values())
            keys = list(ranking.keys())
            
            if items[0] == items[1]:
                print(" ".join([str(key + 1) for key in keys]))
            else:
                print(keys[0] + 1)
        
    games, pilots = list(map(int, input().split()))