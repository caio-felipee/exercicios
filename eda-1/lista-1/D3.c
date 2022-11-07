#include <stdio.h>

int main(void) {
    int current_day = 0, restaurants = 0;

    while (scanf("%d", &restaurants) == 1) {
        int best_restaurant_id = -1, best_restaurant_stars = -1;

        current_day++;

        for(restaurants; restaurants > 0; restaurants--) {
            int restaurant_id = -1, restaurant_stars = -1;

            scanf("%d %d", &restaurant_id, &restaurant_stars);

            if (restaurant_stars >= best_restaurant_stars) {
                if (restaurant_stars == best_restaurant_stars && restaurant_id > best_restaurant_id) continue;

                best_restaurant_id = restaurant_id;
                best_restaurant_stars = restaurant_stars;
            }
        }

        printf("Dia %d\n%d\n\n", current_day, best_restaurant_id);
    }
}