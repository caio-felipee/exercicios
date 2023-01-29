#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct node {
    Item id;
    struct node *next;
} node;

typedef struct {
    int count;
    struct node *first;
    struct node *last;
} root;

void initialize_list(root *h) {
    h->first = NULL;
    h->last = NULL;
    h->count = 0;
}

void remove_first(root *h) {
    node *aux = h->first;

    if(h->first == h->last)
        h->last = NULL;

    h->first = aux->next;
    h->count--; 

    free(aux);
}

void remove_item(root *h, int position) {
    if(position == 1) return remove_first(h);

    node *aux = h->first;

    for(int i = 2; i < position; i++) { // [1] [2] [3] [4] 
        aux = aux->next;
    }

    node *toremove = aux->next;
    
    aux->next = toremove->next;

    if(position == h->count)
        h->last = aux;

    h->count--;

    free(toremove);
}

void add_item(root *h, Item id) {
    node *item = malloc(sizeof(node));

    if(!h->first)
        h->first = item;
    else
        h->last->next = item;
    
    item->next = NULL;
    item->id = id;

    h->count++;
    h->last = item;
}

Item get_first_element(root *h) {
    return h->first->id;
}

int main(void) {
    int tmp, P, R, N = 0;

    while(scanf(" %d %d", &P, &R) != EOF && P != 0 && R != 0) {
        root h;

        initialize_list(&h);

        for(int i = 0; i < P; i++) {
            scanf(" %d", &tmp);

            add_item(&h, tmp);
        }

        int players, chosen, action;

        for(int i = 0; i < R; i++) {
            int eliminated = 0;

            scanf(" %d %d", &players, &chosen);
            
            for(int j = 1; j <= players; j++) {
                scanf(" %d", &tmp);

                if(chosen != tmp) {
                    remove_item(&h, j - eliminated);

                    ++eliminated;
                }
            }
        }

        printf("Teste %d\n%d\n\n", ++N, get_first_element(&h));
    }

    return 0;
}