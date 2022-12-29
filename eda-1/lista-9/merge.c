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
    int v[100000];
    int n = 0;

    while(scanf("%d", &v[n++]) != EOF);
    
    n--;

    mergesort(v, 0, n - 1);

    for(int i = 0; i < n; i++)
        printf("%d%s", v[i], i - 1 == n ? "\n" : " ");
}