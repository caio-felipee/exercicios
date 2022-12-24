#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

int main(void) {
    int v[2000], n = 0;

    while(scanf("%d", &v[n++]) != EOF);

    n--;

    for(int i = 0; i < n; i++) {
        int min = i;

        for(int j = i + 1; j < n; j++) {
            if(v[min] > v[j]) min = j;
        }

        swap(&v[i], &v[min]);
    }

    printf("%d", v[0]);

    for(int i = 1; i < n; i++)
        printf(" %d", v[i]);
    
    printf("\n");
    return 0;
}