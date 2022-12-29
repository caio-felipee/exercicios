#include <stdio.h>

int binarysearch(int *v, int value, int left, int right) {
    int mid;

    while(right >= left) {
        mid = left + (right - left) / 2;

        if(value == v[mid]) return mid;
        if(value < v[mid]) right = mid - 1;
        else left = mid + 1;
    }

    int best = mid;

    if(best > 0 && value < v[best - 1]) best -= 1;
    else if(value > v[best]) best += 1;

    return best;
}

int main(void) {
    int n, m, t;

    scanf("%d %d", &n, &m);

    int v[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    while(m--) {
        scanf("%d", &t);

        int ans = binarysearch(v, t, 0, n - 1);

        printf("%d\n", ans);
    }

    return 0;
}