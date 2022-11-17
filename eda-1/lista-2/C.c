#include <stdio.h>

int main(void) {
    int msg[1000], i = 0;

    while(scanf("%x", &msg[i]) == 1) i++;

    char *pmsg = msg;

    printf("%s\n", pmsg);

    return 0;
}