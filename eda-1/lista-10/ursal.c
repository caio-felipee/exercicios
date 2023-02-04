#include <stdio.h>

typedef struct {
    int id;
    int level; // 1 -> Presidente / 2 -> Senador / 3 -> Dep. Fed. / 4 -> Dep. Est.
    int votes;
} Item;

#define swap(A, B) { Item t = A; A = B; B = t; }
#define key(A) A.votes

int i = 0;
int total_votes_type[4] = { 0 };

Item running[800000];

void sort_id(Item *v, int l, int r) {
    int j = r;
    Item tmp = v[r];

    while(v[j].id < v[j - 1].id && j > i)
        swap(v[j], v[--j]);
}

int binary_search(Item *v, int item, int l, int r) {
    while(l <= r) {
        int mid = l + (r - l) / 2;

        if(v[mid].id == item) return mid;
        if(v[mid].id > item) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}

void add_vote(int id) {
    int index = binary_search(running, id, 0, i - 1);

    if(index == -1) {
        int level;

        if(id < 100)
            level = 1;
        else if(id < 1000)
            level = 2;
        else if(id < 10000)
            level = 3;
        else
            level = 4;

        total_votes_type[level]++;
        running[i] = (Item) { id, level, 1 };

        sort_id(running, 0, i);
        i++;
    }

    else {
        running[index].votes++;
    }
}

void merge(Item *v, int l, int m, int r) {
    Item R[r - l + 1];

    int k = 0, i = l, j = m + 1;

    while(i <= m && j <= r) 
        if(key(v[i]) <= key(v[j])) R[k++] = v[i++];
        else R[k++] = v[j++];
    
    while(i <= m) R[k++] = v[i++];
    while(j <= r) R[k++] = v[j++];

    k = 0;

    printf("\n\n");
    for(int i = l; i <= r; i++) {
        v[i] = R[k++];
        
        printf("sorted %d %d\n", v[i].id, v[i].votes);
    }
}

void mergesort(Item *v, int l, int r) {
    if(l >= r) return;

    int mid = l + (r - l) / 2;

    mergesort(v, l, mid);
    mergesort(v, mid + 1, r);
    merge(v, l, mid, r);
}

int main(void) {
    long long int p = 1, s, f, e;

    scanf("%lld %lld %lld", &s, &f, &e);

    long long int total = 0, invalid = 0;
    int vote;

    while(scanf(" %d", &vote) != EOF) {
        if(vote < 10)
            invalid++;
        else 
            add_vote(vote);

        total++;
    }

    // Now we will sort the intervals [l, r], according to the type.
    int pi = total_votes_type[0], si = pi + total_votes_type[1], dfi = si + total_votes_type[2];

    mergesort(running, 0, pi - 1);
    mergesort(running, pi, si - 1);
    mergesort(running, si, dfi - 1);
    mergesort(running, dfi, i - 1);

    printf("%d\n", running[0].id);
}