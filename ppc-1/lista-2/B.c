#include <stdio.h>

int main(void) {
    int height = 0, width = 0;

    scanf("%d %d", &height, &width);

    char matrix[height + 2][width + 2];

    for(int r = 0; r < height + 2; r++) {
        for(int c = 0; c < width + 2; c++) {
            if(r == 0 || r == height + 1 || c == 0 || c == width + 1) matrix[r][c] = '#';
            else scanf(" %c", &matrix[r][c]); 
        }
    }

    /*
    * Laço criado apenas para uma melhor visualização
    * de como seria a matriz. Ao utilizar o mesmo laço
    * de cima, haveria uma mistura de entrada com saída.
    */

    for(int r = 0; r < height + 2; r++) {
        for(int c = 0; c < width + 2; c++) {
            printf("%c", matrix[r][c]);
        }

        printf("\n");
    }
}