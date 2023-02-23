#include <stdio.h>
#define exch(A, B) { int t = A; A = B; B = t; }

int partition(int *v, int l, int r) {
    int i = l - 1, j = r, k = v[r];

    while(1) {
        while(v[++i] < k);
        while(v[--j] > k) if(j == l) break;

        if(i >= j) break;
        exch(v[i], v[j]);
    }

    exch(v[i], v[r]);

    return i;
}

void insertionsort(int *v, int l, int r) {
    for(int i = r; i > l; i--)
        if(v[i - 1] > v[i]) exch(v[i - 1], v[i]);
    
    for(int i = l + 2; i <= r; i++) {
        int tmp = v[i], j = i;

        while(v[j - 1] > tmp) {
            v[j] = v[j - 1];
            j--;
        }

        v[j] = tmp;
    }
}

void quicksort(int *v, int l, int r) {
    if(r - l <= 30) return;

    int p = partition(v, l, r);

    quicksort(v, l, p - 1);
    quicksort(v, p + 1, r);
}

void sort(int *v, int l, int r) {
    quicksort(v, l, r);
    insertionsort(v, l, r);
}

int main(void) {
    int n;

    scanf("%d", &n);

    int v[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    sort(v, 0, --n);

    for(int i = 0; i <= n; i++)
        printf("%d%c", v[i], i < n ? ' ' : '\n');
        
    return 0;
}   