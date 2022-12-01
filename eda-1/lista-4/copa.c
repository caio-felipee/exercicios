#include <stdio.h>

int main(void) {
    int teams, rounds, points_winner = 3;

    while(scanf("%d %d", &teams, &rounds) == 2 && teams) {
        int points_remainder = 0, points = 0, max_points = rounds * 3;
        char buf[11];

        for(int i = 0; i < teams; i++) {
            scanf("%s %d", buf, &points);

            points_remainder += points;
        }

        if(teams > 0) printf("%d\n", max_points - points_remainder);
    }
}