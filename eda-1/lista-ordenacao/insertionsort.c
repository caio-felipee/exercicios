#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

void insertionsort(int *v, int l, int r) {
    for(int i = r - 1; i > l; i--)
        if(v[i - 1] > v[i]) swap(&v[i - 1], &v[i]);
    
    for(int i = l + 2; i < r; i++) {
        int tmp = v[i], j = i;

        while(v[j - 1] > tmp) {
            v[j] = v[j - 1];
            j--;
        }

        v[j] = tmp;
    }
}

int main(void) {
    int v[55000], n = 0;

    while(scanf("%d", &v[n++]) != EOF);

    n--;

    insertionsort(v, 0, n);
    printf("%d", v[0]);

    for(int i = 1; i < n; i++)
        printf(" %d", v[i]);
    
    printf("\n");
    return 0;
}