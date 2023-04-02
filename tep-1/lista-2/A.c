#include <stdio.h>

int main(void) {
    short num_chosen[2], groups[12] = { 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1 };

    scanf("%hd %hd", &num_chosen[0], &num_chosen[1]);

    if(groups[num_chosen[0] - 1] == groups[num_chosen[1] - 1]) printf("Yes\n");
    else printf("No\n");

    return 0;
}