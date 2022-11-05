/*
* 
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    short index = 0, times_said_yes = 0, minimum_acceptance = 2, form_size = 10, times_to_go = 0;
    char answer[4], affirmative_word[] = "sim\0";

    while (scanf("%s", &answer) == 1) {
        index++;

        if (strcmp(answer, affirmative_word) == 0) times_said_yes++;

        if (index == form_size) {
            if (times_said_yes >= minimum_acceptance) times_to_go++;

            times_said_yes = 0;
            index = 0;
        }
    }

    printf("%d\n", times_to_go);
}

