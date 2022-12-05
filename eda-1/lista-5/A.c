#include <stdio.h>

int get_pairs(char *letters, int index, int pairs) {
    char *curr = letters + index;

    if(*curr == 0) return pairs;
    if(index > 0 && *(curr - 1) == *(curr + 1)) pairs++;

    return get_pairs(letters, index + 1, pairs);
}

int main(void) {
    char letters[201];

    scanf("%200s", letters);

    printf("%d\n", get_pairs(letters, 0, 0));
    return 0;
}