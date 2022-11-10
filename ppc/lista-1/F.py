while True:
    try:
        index = 0

        players, rounds = [int(x) for x in input().split()]
        points = [int(x) for x in input().split()]

        player_stats = [0 for _ in range(players)]

        for _ in range(rounds):
            for i in range(players):
                player_stats[i] = player_stats[i] + points[index]
                index = index + 1
    
        winner_id, winner_points = 0, 0

        for i in range(players):
            if player_stats[i] >= winner_points:
                winner_id = i
                winner_points = player_stats[i]
    
        print(winner_id + 1)

    except EOFError:
        break