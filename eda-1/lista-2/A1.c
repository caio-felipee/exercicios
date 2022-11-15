#include <stdio.h>

int main(void) {
    int count = 0, total = 0, guess = 0, buffer = 0;

    scanf("%d", &count);

    for(count; count > 0; count--) {
        scanf("%i", &buffer);

        total += buffer;
    }

    scanf("%i", &guess);

    if(total == guess) printf("Acertou\n");
    else printf("Errou\n");

    return 0;
}