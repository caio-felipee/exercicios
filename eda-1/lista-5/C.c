#include <stdio.h>

void print_reverse(char *letters) {
    if(*letters == 0) return;

    print_reverse(letters + 1);
    printf("%c", *letters);
}

int main(void) {
    char letters[501];

    scanf("%s", letters);

    print_reverse(letters);
    return 0;
}