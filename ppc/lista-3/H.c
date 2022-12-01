#include <stdio.h>
#include <string.h>

int main(void) {
    int num_slogans, num_said;

    scanf("%d", &num_slogans);

    char slogans[num_slogans][101], answers[num_slogans][102];

    for(int i = 0; i < num_slogans; i++) {
        scanf(" %[^\n]", &slogans[i]);
        scanf(" %[^\n]", &answers[i]);
    }

    scanf("%d", &num_said);

    while(num_said--) {
        char slogan[101];

        scanf(" %[^\n]", slogan);

        for(int j = 0; j < num_slogans; j++) {
            int ans = 1;
            for(int i = 0; i < 101; i++) {
                if(slogans[j][i] == 0 && slogan[i] == 0) break;
                if(slogans[j][i] != slogan[i]) {
                    ans = 0;
                    break;
                };
            }

            if(ans == 1) {
                printf("%s\n", answers[j]);
                break;
            }

        }
    }
}