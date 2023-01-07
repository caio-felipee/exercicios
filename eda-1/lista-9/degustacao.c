#include <stdio.h>

typedef struct {
    int occurrences;
    int position;
    char character;
} Item;

#define highereq(A, B) key(A) >= key(B)
#define key(A) A.occurrences

void merge(Item *v, int l, int m, int r) {
    Item R[r - l + 1];

    int i = l, j = m + 1, k = 0;

    while(i <= m && j <= r) {
        if(highereq(v[i], v[j]))
            R[k++] = v[i++];
        else
            R[k++] = v[j++];
    }

    while(i <= m)
        R[k++] = v[i++];
    
    while(j <= r)
        R[k++] = v[j++];
    
    k = 0;

    for(int n = l; n <= r; n++)
        v[n] = R[k++];
}

void mergesort(Item *v, int l, int r) {
    if(l >= r) return;

    int mid = l + (r - l) / 2;

    mergesort(v, l, mid);
    mergesort(v, mid + 1, r);
    merge(v, l, mid, r);
}

int main(void) {
    Item chars[100000];

    char tmp;
    int n = 0, position = 0;

    while(scanf("%c", &tmp) && tmp != '\n') {
        if(chars[n].character != tmp) {
            if(position > 0)
                ++n;

            chars[n].position = position;
            chars[n].character = tmp;
            chars[n].occurrences = 1;
        }

        else
            chars[n].occurrences++;

        position++;
    }

    mergesort(chars, 0, n);

    for(int i = 0; i <= n; i++) 
        printf("%d %c %d\n", chars[i].occurrences, chars[i].character, chars[i].position);

    return 0;
}