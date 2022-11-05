/*
* 
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    char random_word[31], chosen_word[] = "marte\0";
    bool flag = false;

    while (scanf("%s", &random_word) == 1) {
        if (strcmp(random_word, chosen_word) == 0) flag = true;
    }

    if (flag) printf("Leonardo Cicero Marciano\n");
    else printf("none\n");

    return 0;
}