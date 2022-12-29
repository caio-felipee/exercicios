#include <stdio.h>

void merge(int *v, int l, int m, int r) {
    int R[r - l + 1];

    int k = 0, i = l, j = m + 1;

    while(i <= m && j <= r) 
        if(v[i] <= v[j]) R[k++] = v[i++];
        else R[k++] = v[j++];
    
    while(i <= m) R[k++] = v[i++];
    while(j <= r) R[k++] = v[j++];

    k = 0;

    for(int i = l; i <= r; i++)
        v[i] = R[k++];
}

void mergesort(int *v, int l, int r) {
    if(l >= r) return;

    int mid = l + (r - l) / 2;

    mergesort(v, l, mid);
    mergesort(v, mid + 1, r);
    merge(v, l, mid, r);
}

int binarysearch(int *v, int value, int left, int right) {
    while(right >= left) {
        int mid = left + (right - left) / 2;

        if(value == v[mid]) return 1;
        if(value < v[mid]) right = mid - 1;
        else left = mid + 1;
    }

    return 0;
}

int main(void) {
    int n, t;

    scanf("%d", &n);

    int v[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    mergesort(v, 0, n - 1);

    while(scanf("%d", &t) != EOF)
        printf(binarysearch(v, t, 0, n - 1) ? "sim\n" : "nao\n");
    
    return 0;
}