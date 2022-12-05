#include <stdio.h>

void exchange_x(char *letters, char to_exch, int index) {
    if(*(letters + index) == 0) return;
    if(*(letters + index) == 'x') *(letters + index) = to_exch;

    return exchange_x(letters, to_exch, index + 1);
}

int main(void) {
    char letters[81];

    scanf("%s", letters);

    exchange_x(letters, 'y', 0);

    printf("%s\n", letters);
    return 0;
}