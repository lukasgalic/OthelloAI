#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "strategy.h"

void human_strategy(char board[SIZE][SIZE])
{
    char player_move[4];
    int row, col;
    while (1)
    {
        int valid_moves[SIZE][SIZE];
        find_valid_moves(board, valid_moves, 'B');
        print_board(board, valid_moves);
        printf("Your move (e.g., 'd3'): ");
        fgets(player_move, sizeof(player_move), stdin);

        // Validera inmatningen
        if (strlen(player_move) == 3 &&
            player_move[0] >= 'a' && player_move[0] <= 'h' &&
            player_move[1] >= '1' && player_move[1] <= '8')
        {
            input_to_index(player_move, &row, &col);
            printf("Valid move: %d, %d\n", row, col);
            break;
        }
        else
        {
            printf("\nNot a valid move, try again.\n");
        }
    }
}

void random_strategy(char board[SIZE][SIZE])
{
    printf("not implemented yet.\n");
}

void optimal_strategy(char board[SIZE][SIZE])
{

    printf("not implemented yet.\n");
}
