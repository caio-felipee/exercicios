#include <stdio.h>

int main(void) {
    int diameter, width, height, profundity;

    scanf("%d", &diameter);
    scanf("%d %d %d", &width, &height, &profundity);

    if(width < diameter || height < diameter || profundity < diameter) printf("N\n");
    else printf("S\n");

    return 0;
}