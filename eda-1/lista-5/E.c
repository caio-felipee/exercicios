#include <stdio.h>

void ultrapassa_minimamente(int *numbers, int maximum, int sum) {
    if(*numbers == 0) return;
    if(*numbers + sum > maximum) {
        ultrapassa_minimamente(numbers + 1, maximum, 0);
        printf("%d\n", *numbers);
    }
    else ultrapassa_minimamente(numbers + 1, maximum, sum + *numbers);
}

int main(void) {
    int numbers[4096], maximum, i = 0;

    while(scanf(" %d", &numbers[i]) && numbers[i++]);

    scanf(" %d", &maximum);
    ultrapassa_minimamente(numbers, maximum, 0);
    return 0;
}