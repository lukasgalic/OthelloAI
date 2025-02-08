#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "strategy.h"

int main(void)
{
    char board[SIZE][SIZE] = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', 'B', '.', '.', '.'},
        {'.', '.', '.', 'B', 'W', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'}};

    char play_choice[3];

    printf("\nOwn Play | Random --> P | R\n");
    fgets(play_choice, sizeof(play_choice), stdin);

    char choice = play_choice[0];

    if (choice == 'p' || choice == 'P')
    {
        while (1)
        {
            human_strategy(board, 'B');
            random_strategy(board, 'W');
        }
    }
    else if (choice == 'r' || choice == 'R')
    {
        while (1)
        {
            random_strategy(board, 'B');
            random_strategy(board, 'W');
        }
    }
    else
    {
        printf("Wrong input, goodbye!\n");
        exit(0);
    }

    return 0;
}
