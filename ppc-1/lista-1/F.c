#include <stdio.h>

int main(void) {
    int players = 0, rounds = 0;

    while (scanf("%d %d", &players, &rounds) == 2) {
        int player_stats[500] = {0}, winner_id = -1, winner_points = -1;

        for(rounds; rounds > 0; rounds--) {
            for(int player = 0; player < players; player++) {
                int player_points = 0;

                scanf("%d", &player_points);

                player_stats[player] += player_points;

            }
        }

        for(int i = 0; i < players; i++) {
            if(player_stats[i] >= winner_points) {
                winner_id = i;
                winner_points = player_stats[i];
            }
        }

        printf("%d\n", winner_id + 1);
    }
}