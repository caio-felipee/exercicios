#include <stdio.h>

void get_winners(char *teams, char *winners, int games) {
    int a, b;

    for(int i = 0; i < games; i++) {
        scanf("%d %d", &a, &b);

        if(a > b) winners[i] = teams[i * 2];
        else winners[i] = teams[i * 2 + 1];
    }
}

int main(void) {
    char sixteen[] = "ABCDEFGHIJKLMNOP\0", quarter[8], semi[4], final[2], winners[2];

    get_winners(sixteen, quarter, 8);
    get_winners(quarter, semi, 4);
    get_winners(semi, final, 2);
    get_winners(final, winners, 1);

    printf("%c\n", winners[0]);
    return 0;
}