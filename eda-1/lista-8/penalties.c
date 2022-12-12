#include <stdio.h>

int main(void) {
    int n, f_points = 0, s_points = 0;

    scanf("%d", &n);

    char first_team[n + 1], second_team[n + 1];

    scanf("%s", first_team);
    scanf("%s", second_team);

    for(int i = 1; i <= 2 * n; i++) {
        if(i&1) f_points += first_team[i / 2] == 'o';
        else s_points += second_team[i / 2 - 1 + i % 2] == 'o';

        if(f_points > s_points + ((2 * n - i) / 2) + i % 2|| s_points > f_points + ((2 * n - i) / 2)) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("Empate\n");
    return 0;
}