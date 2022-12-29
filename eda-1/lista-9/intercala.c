#include <stdio.h>

int m[800000];

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

int main(void) {
    int index = 0, n;

    for(int i = 0; i < 8; i++) {
        scanf("%d", &n);
        if(n == 0) continue;

        for(int j = 0; j < n; j++) 
            scanf("%d", &m[index + j]);
        

        merge(m, 0, index - 1, index + n - 1);

        index += n;
    }

    for(int i = 0; i < index; i++)
        printf("%d%s", m[i], i == index - 1 ? "\n" : " ");
    
    return 0;
}