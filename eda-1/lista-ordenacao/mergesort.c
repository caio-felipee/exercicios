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

int main(void) {
    int n;

    scanf("%d", &n);

    int v[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    mergesort(v, 0, n - 1);

    for(int i = 0; i < n; i++)
        printf("%d%s", v[i], i == n - 1 ? "\n" : " ");
}