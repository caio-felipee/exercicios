#include <stdio.h>

int main(void) {
    int games = 0, pilots = 0;

    while(scanf("%d %d", &games, &pilots) == 2) {
        if(games == 0 || pilots == 0) break;

        int scores = 0, scoring_system[100][100] = { -1 }, game_result[100][100] = { -1 };

        for(int i = 0; i < games; i++) {
            for(int p = 0; p < pilots; p++) {
                scanf(" %d", &game_result[i][p]);
            }
        }

        scanf("%d", &scores);

        for(int i = 0; i < scores; i++) {
            int receivable = 0;

            scanf("%d", &receivable);

            for(int j = 0; j < receivable; j++) {
                scanf(" %d", &scoring_system[i][j]);
            }
        }
    }
}