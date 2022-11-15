#include <stdio.h>

int main(void) {
    int guess, first_check, second_check, third_check;

    scanf("%d %d %d", &first_check, &second_check, &third_check);
    scanf("%d", &guess);

    if(first_check + second_check + third_check == guess) printf("Acertou\n");
    else printf("Errou\n");

    return 0;
}