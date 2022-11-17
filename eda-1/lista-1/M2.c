#include <stdio.h>
#include <string.h>

int main(void) {
    int num_lines = 0, current_line = 0, current_column = 0;

    scanf("%d", &num_lines);

    char text[1000][1002] = { 0 }, up_keyword[] = {'k', '\0'}, down_keyword[] = {'j', '\0'}, current_keyword[2], index = 0;

    for(int i = -1; i < num_lines; i++) {
        fgets(text[i], 1002, stdin);
    }

    scanf(" %d %d", &current_line, &current_column);

    current_line--;
    current_column--;

    while(scanf("%s", &current_keyword) != EOF) {
        if(strcmp(up_keyword, current_keyword) == 0) index = -1;
        else index = 1;

        if(index + current_line <= num_lines && index + current_line >= 0) current_line += index;

        for(int i = current_column; i >= 0; i--) {
            if(text[current_line][i] != 0 && text[current_line][i] != 10) {
                printf("%d %d %c\n", current_line + 1, i + 1, text[current_line][i]);
                break;
            }
        }
    }
}