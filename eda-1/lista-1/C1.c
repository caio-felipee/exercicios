/*
* 
*/

#include <stdio.h>

int main(void) {
    int tests_in_row = 0, coins_to_deposit = 0;

    scanf("%i", &coins_to_deposit);

    while (coins_to_deposit > 0) {
        tests_in_row++;

        printf("Teste %d\n", tests_in_row);

        int first_safe = 0, second_safe = 0; // Quantidade de dinheiro depositada em cada cofre

        for (int i = 0; i < coins_to_deposit; i++) {
            int new_first_safe_deposit = 0, new_second_safe_deposit = 0;

            scanf("%d %d", &new_first_safe_deposit, &new_second_safe_deposit);

            first_safe += new_first_safe_deposit;
            second_safe += new_second_safe_deposit;

            printf("%d\n", first_safe - second_safe);
        }

        scanf("%i", &coins_to_deposit);
        printf("\n"); // Pulando uma linha
    }

    return 0;
}