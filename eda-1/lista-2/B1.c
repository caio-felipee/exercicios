#include <stdio.h>

int faz_conta_direito(int parcelas, char op) {
    int total, buff = 0;

    scanf("%d", &total);

    for(parcelas; parcelas > 1; parcelas--) {
        scanf("%d", &buff);

        if(op == '+') total += buff;
        else total -= buff;
    }

    return total;
}