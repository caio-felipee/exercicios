#include <stdio.h>
#include <stdlib.h>
#define SIZE 50000

int top;

void push(char *stack, int *top, char item) {
    *top = *top + 1;

    stack[*top] = item;
}

void pop(char *stack, int *top) {
    *top = *top - 1;
}

int main(void) {
    int N;

    scanf("%d%*c", &N);

    while(N--) {
        int valid = 1;

        char *stack = malloc(sizeof(char) * SIZE), tmp;

        top = -1;

        while(scanf("%c", &tmp) != EOF && tmp != '\n') {

            if(tmp == '(' || tmp == '{' || tmp == '[')
                push(stack, &top, tmp);
            else if(top >= 0 && ((stack[top] == '(' && tmp == ')') || (stack[top] == '{' && tmp == '}') || (stack[top] == '[' && tmp == ']')))
                pop(stack, &top);
            else
                valid = 0;
        }

        if(valid && top == -1)
            printf("S\n");
        else
            printf("N\n");

        free(stack);
    }

    return 0;
}