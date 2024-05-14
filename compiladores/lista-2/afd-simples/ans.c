#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// {estados, alfabeto, função de transição, estado inicial, estados finais}

const int MAX = 1e5;

typedef struct Linked_List {
    int value;
    struct Linked_List *next;
} Linked_List;

typedef struct {
    bool final;
    Linked_List *ft;
} af;

int cmp_alph(const void* a, const void* b)
{
    return *(char*)a - *(char*)b;
}

int get_index(char value, int alph_qt, char* alphabet)
{
    char *v = (char*)bsearch(&value, alphabet, alph_qt, sizeof(char), cmp_alph);

    int index = v - alphabet;
    return index;
}

bool process_word(int curr, char *st, int q0, int alph_qt, char* alphabet, af *aut)
{
    if(!st[curr])
        return aut[q0].final;

    int index = get_index(st[curr], alph_qt, alphabet);

    bool ans = false;
    for(Linked_List *it = aut[q0].ft[index].next; it != NULL; it = it->next)
    {
        ans |= process_word(curr + 1, st, it->value, alph_qt, alphabet, aut); 
    }

    return ans;
}

void push(Linked_List *list, int value)
{
    Linked_List *l = malloc(sizeof(Linked_List));
    l->next = list->next;
    l->value = value;
    list->next = l;
}

void solve()
{
    int state_qt, alph_qt;
    scanf(" %d %d", &state_qt, &alph_qt);
    
    char *alphabet = malloc(sizeof(char) * alph_qt);
    for(int i = 0; i < alph_qt; i++)
        scanf(" %c", &alphabet[i]);

    qsort(alphabet, alph_qt, sizeof(char), cmp_alph);
    
    af *aut = malloc(sizeof(af) * (state_qt + 1));
    for(int i = 0; i <= state_qt; i++)
    {
     
        Linked_List *f = calloc(alph_qt, sizeof(Linked_List));
        aut[i].ft = f;
        aut[i].final = false;
    }

    int from, to;
    char symbol;
    for(int i = 1; i <= state_qt * alph_qt; i++)
    {
        scanf(" %d %c %d", &from, &symbol, &to);
        int index = get_index(symbol, alph_qt, alphabet);

        push(&aut[from].ft[index], to);
    }
    
    int start, final;
    scanf(" %d %d", &start, &final);
    
    for(int i = 1; i <= final; i++)
    {
        scanf(" %d", &to);
        aut[to].final = true;
    }

    char *st = malloc(sizeof(char) * MAX);
    scanf(" %s", st);

    bool ans = process_word(0, st, start, alph_qt, alphabet, aut);
    printf("%s\n", ans ? "Aceito" : "Rejeito");
}

int main()
{
    int t = 1;

    while(t--)
        solve();
}
