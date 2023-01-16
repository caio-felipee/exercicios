#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define key(A) A.japanese

typedef struct {
    char translated[81];
    char japanese[81];
} Item;

int lesseq(char *a, char *b) {
    int i = -1;

    while(1) {
        ++i;

        if(a[i] == 0 && b[i] == 0)
            return 2;

        if(a[i] == 0 || a[i] < b[i])
            return 1;

        if(b[i] == 0 || a[i] > b[i])
            return 0;
    }
}

void merge(Item *v, int l, int m, int r) {
    Item R[r - l + 1];

    int i = l, j = m + 1, k = 0;

    while(i <= m && j <= r)
        if(lesseq(v[i].japanese, v[j].japanese))
            R[k++] = v[i++];
        else
            R[k++] = v[j++];
    
    while(i <= m)
        R[k++] = v[i++];
    
    while(j <= r)
        R[k++] = v[j++];
    
    k = 0;

    for(int i = l; i <= r; i++)
        v[i] = R[k++];
}

void mergesort(Item *v, int l, int r) {
    if(l >= r) return;

    int m = l + (r - l) / 2;

    mergesort(v, l, m);
    mergesort(v, m + 1, r);
    merge(v, l, m, r);
}

int binary_search(Item *v, char *word, int l, int r) {
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int verif = lesseq(v[mid].japanese, word);

        if(verif == 2) return mid;
        if(verif) l = mid + 1;
        else r = mid - 1;
    }

    return -1;
}

void translate(Item *dictionary, char *word, char display, int size) {
    int index = binary_search(dictionary, word, 0, size);

    if(!display)
        display = '\n';

    if(index == -1)
        printf("%s%c", word, display);
    else
        printf("%s%c", dictionary[index].translated, display);
}

int main(void) {
    int t;

    scanf("%d", &t);

    while(t--) {
        int m, n;

        scanf(" %d %d ", &m, &n);

        Item words[m];

        for(int i = 0; i < m; i++) {
            int j = 0, k = 0;

            while(scanf("%c", &words[i].japanese[j]) && words[i].japanese[j] != '\n') j++;
            while(scanf("%c", &words[i].translated[k]) && words[i].translated[k] != '\n') k++;
            
            words[i].japanese[j] = 0;
            words[i].translated[k] = 0;
        }

        mergesort(words, 0, m - 1);

        while(n--) {
            char query[81], tmp;

            while(scanf("%s%c", query, &tmp) != EOF) {
                translate(words, query, tmp, m - 1);
                
                if(tmp == '\n')
                    break;
            }
        }
    }
}