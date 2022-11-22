#include <stdio.h>
#include <string.h>

int main(void) {
    int queries = 0;

    scanf("%d", &queries);

    int stack[queries][2], index = -1;

    while(queries--) {
        char str[15];
        int num;

        scanf("%s", &str);

        if(strcmp("PUSH", str) == 0) {
            scanf("%d", &num);

            index++;

            if(index > 0 && num > stack[index - 1][1] && stack[index - 1][1] != -1) stack[index][1] = stack[index - 1][1];
            else stack[index][1] = num;

            stack[index][0] = num;
        }

        if(strcmp("MIN", str) == 0) {
            if(index >= 0 && stack[index][0] != -1) printf("%d\n", stack[index][1]);
            else printf("EMPTY\n");
        }

        if(strcmp("POP", str) == 0) {
            if(index == 0 && stack[index][0] != -1) {
                stack[index][0] = -1;
                stack[index][1] = -1;
            } 
            
            else if(index - 1 < 0) printf("EMPTY\n");
            else index--;
        }   
    }
}