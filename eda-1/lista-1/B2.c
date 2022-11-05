/*
* Exercício com o objetivo de fazer uma soma entre
* uma quantidade de números inteiros pré-definida
* na entrada 'index'.
*/

#include <stdio.h>

int main(void) {
    int index = 0, sum = 0, current_number = 0;

    scanf("%i", &index);

    for(int i = 0; i < index; i++) {
        scanf("%d", &current_number);

        sum += current_number;
    }

    printf("%d\n", sum);
    return 0;
}