#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Item;

#define key(A) A.value
#define lesseq(A, B) key(A) <= key(B)

void merge(Item *v, int l, int m, int r) {
    Item R[r - l + 1];

    int i = l, j = m + 1, k = 0;

    while(i <= m && j <= r) 
        if(lesseq(v[i], v[j])) 
            R[k++] = v[i++];
        else 
            R[k++] = v[j++];
    
    while(i <= m) 
        R[k++] = v[i++];

    while(j <= r)
        R[k++] = v[i++];

    k = 0;

    for(int i = l; i <= r; i++) {
        v[i] = R[k++];
    }
}

void mergesort(Item *v, int l, int r) {
    if(l >= r) return;

    int m = l + (r - l) / 2;

    mergesort(v, l, m);
    mergesort(v, m + 1, r);
    merge(v, l, m, r);
}

int binarysearch(Item *v, int value, int l, int r) {
    while(l <= r) {
        int mid = l + (r - l) / 2;

        if(value == key(v[mid])) return v[mid].index;
        if(value > key(v[mid])) l = mid + 1;
        else r = mid - 1;
    }

    return -1;
}

int main(void) {
    int n, m, tmp;

    scanf("%d %d", &n, &m);

    Item v[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);

        v[i].value = tmp;
        v[i].index = i;
    }

    mergesort(v, 0, n - 1);

    while(m--) {
        scanf("%d", &tmp);
        printf("%d\n", binarysearch(v, tmp, 0, n - 1));
    }
    
    return 0;
}