#include <stdio.h>

int sum_digits(char *digits, int index, int value) {
    if(*(digits + index) == 0) return value;

    return sum_digits(digits, index + 1, value + (*(digits + index) - '0'));
}

int main(void) {
    char str[15];

    scanf("%s", str);

    printf("%d\n", sum_digits(str, 0, 0));
    return 0;
}