#include <stdio.h>

#define key(A) A.size
#define max(A, B) { A > B ? A : B }
#define min(A, B) { A < B ? A : B }

int i;

typedef struct {
    int size;
    int directions[2];
} Boots;

int binary_search(Boots *boots, int item, int r) {
    int l = 0, m;

    while(l <= r) {
        m = l + (r - l) / 2;

        if(key(boots[m]) == item) return m;
        if(key(boots[m]) < item) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

void sort(Boots *boots, int right) {
    int j = right;

    while(j > 0 && key(boots[j]) < key(boots[j - 1])) {
        Boots tmp = boots[j];

        boots[j] = boots[j - 1];
        boots[j - 1] = tmp;

        --j;
    }
}

void add_boot(Boots *boots, int size, char direction) {
    int search = binary_search(boots, size, i);

    if(search == -1) {        
        boots[i].size = size;
        boots[i].directions[0] = direction == 'E' ? 1 : 0;
        boots[i].directions[1] = direction == 'D' ? 1 : 0;

        sort(boots, i);

        ++i;
    }

    else if(direction == 'E') {
        boots[search].directions[0]++;
    }

    else
        boots[search].directions[1]++;    
}

int main(void) {
    int n;
    
    while(scanf(" %d", &n) != EOF) {
        i = 0;

        int ans = 0, tmp_s;
        char tmp_d;

        Boots boots[n];

        for(int j = 0; j < n; j++) {
            if(scanf(" %d %c", &tmp_s, &tmp_d) == 2);
                add_boot(boots, tmp_s, tmp_d);
        }

        for(int j = 0; j < i; j++) 
            ans += (boots[j].directions[0] < boots[j].directions[1] ? boots[j].directions[0] : boots[j].directions[1]);
        
        printf("%d\n", ans);
    }

    return 0;
}