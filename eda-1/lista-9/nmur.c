#include <stdio.h>

#define swap(A, B) { long long int t = A; A = B; B = t; }

void merge(long long int *v, int l, int m, int r) {
    long long int R[r - l + 1];

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

int merge_rep(long long int *v, int l, int m, int r) { // no repetitions allowed
    long long int R[r - l + 1];

    int k = 0, i = l, j = m + 1, rep = 0;

    while(i <= m && j <= r) 
        if(v[i] <= v[j])
            if(k != 0 && R[k - 1] == v[i])
                ++rep, ++i;
            else
                R[k++] = v[i++];

        else
            if(k != 0 && R[k - 1] == v[j])
                ++rep, ++j;
            else
                R[k++] = v[j++];
    
    while(i <= m)
        if(R[k - 1] == v[i])
            ++rep, ++i;
        else
            R[k++] = v[i++];

    while(j <= r)
        if(R[k - 1] == v[j])
            ++rep, ++j;
        else
            R[k++] = v[j++];

    k = 0;

    for(int i = l; i <= r; i++)
        v[i] = R[k++];
    
    return rep;
}

int mergesort(long long int *v, int l, int r, int rep) {
    if(l >= r) return 0;

    int mid = l + (r - l) / 2;

    mergesort(v, l, mid, 0);
    mergesort(v, mid + 1, r, 0);

    if(rep)
        return merge_rep(v, l, mid, r);
    else
        merge(v, l, mid, r);
}

int binarysearch(long long int *v, long long int value, int left, int right) {
    while(right >= left) {
        int mid = left + (right - left) / 2;

        if(value == v[mid]) return mid;
        if(value < v[mid]) right = mid - 1;
        else left = mid + 1;
    }

    return 0;
}

int main(void) {
    int n, i = 0;

    scanf("%d", &n);

    long long int v[n * 2 + 10], t;

    while(i < n) 
        scanf("%lli", &v[i++]);
    
    int rep = mergesort(v, 0, i - 1, 1);

    i -= rep;

    if(i&1) v[i++] = 1000000000;

    int k = 0, in = 0, j = 0;

    for(int j = 0; j < i; j += 2)
        v[i + (in++)] = v[j] + v[j + 1];
    
    i += in;

    rep = mergesort(v, 0, i - 1, 1);

    i -= rep;

    while(j < i) {
        printf("%lli\n", v[j]);

        j += 4;
    }

    printf("Elementos: %d\n", i);
    return 0;
}
