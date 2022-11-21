#include <stdio.h>

int main(void) {
    int tests_number = 0;

    scanf("%d", &tests_number);
    
    for(tests_number; tests_number > 0; tests_number--) {
        int streets, avenues, friends;

        scanf("%d %d %d", &streets, &avenues, &friends);

        int friends_x[friends], friends_y[friends], index = ((friends + 1) / 2) - 1, loc[2];

        for(int i = 0; i < friends; i++) {
            scanf("%d %d", &loc[0], &loc[1]);

            friends_x[i] = loc[0];
            friends_y[i] = loc[1];
        }

    for(int i = 0; i < friends; i++) {
        for(int j = i; j < friends; j++) {
            if(friends_x[i] >= friends_x[j] || (friends_x[i] == friends_x[j] && friends_y[i] > friends_y[j])) {
                int buf_x = friends_x[i], buf_y = friends_y[i];

                friends_x[i] = friends_x[j];
                friends_y[i] = friends_y[j];
                friends_x[j] = buf_x;
                friends_y[j] = buf_y;
            }
        }
    }

        printf("(Street: %d, Avenue: %d)\n", friends_x[index], friends_y[index]);
    }
}