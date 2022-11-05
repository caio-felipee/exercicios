/*
* 
*/

#include <stdio.h>

int main(void) {
    int amount = 0, tmp;

    while (scanf("%i", &tmp) != EOF) {
        amount++;
    }

    printf("%d", amount);
    return 0;
}