#include <stdio.h>

void* read_word(char *word) {
    if(*word == 0) return word;
    else if(*word == 'x') {
        read_word(word + 1); 
        printf("x");
        }

    else {
        printf("%c", *word);
        read_word(word + 1);
    }
}

int main(void) {
    char word[100];

    scanf("%s", word);

    read_word(word);
    printf("\n");
}