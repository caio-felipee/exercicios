/*
* Exercício com objetivo de fazer uma contagem de
* vitórias de uma competição entre duas pessoas,
* definida como 'alice_victories' e 'beto_victories'.
*
* Caso haja algum número de jogos realizados, o programa
* irá realizar a contagem. A próxima entrada deve ser
* uma "representação" de como foi os jogos. 
*
* 0 - Vitória de Alice
* 1 - Vitória de Beto
*/

#include <stdio.h>

int main(void) {
    int games_played = 0;

    scanf("%d", &games_played);

    while (games_played > 0) {
        int alice_victories = 0, beto_victories = 0;
        
        for (int i = 0; i < games_played; i++) {
            int game_victory;

            scanf("%i", &game_victory);

            if (game_victory == 0) alice_victories++;
            else if (game_victory  == 1) beto_victories++;
        }

        printf("Alice ganhou %d e Beto ganhou %d\n", alice_victories, beto_victories);
        scanf("%d", &games_played);
    }

}