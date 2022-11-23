#include <stdio.h>

int f91(int N) {
    if(N >= 101) return N - 10;
    else if (N<=100) return f91(f91(N + 11));
}

int main(void) {
    int num;

    while(scanf("%d", &num) && num) printf("f91(%d) = %d\n", num, f91(num));
}