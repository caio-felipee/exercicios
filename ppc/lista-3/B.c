#include <stdio.h>

int main(void) {
    char letters[27];
    char is_different = 1;

    scanf("%s", letters);

    for(int i = 0; i < 27; i++) {
        if(is_different == -1 || letters[i] == 0) break;

        for(int j = 0; j < 27; j++) {
            if(letters[j] == 0) break;
            if(i != j && letters[i] == letters[j]) {
                is_different = -1;
                break;
            }
        }
    }

    is_different == -1 ? printf("no\n") : printf("yes\n");
    return 0;
}