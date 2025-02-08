#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "board.h"
#include "strategy.h"

void human_strategy(char board[SIZE][SIZE], char player)
{
    char player_move[4];
    int row, col;
    int valid_input = 0;
    while (!valid_input)
    {
        int valid_moves[SIZE][SIZE];
        int possible_moves[SIZE * SIZE][2];
        int move_count = find_valid_moves(board, valid_moves, possible_moves, player);
        print_board(board, valid_moves);
        if (move_count == 0)
        {
            printf("No valid moves for Black, skipping turn.\n");
            check_game_over(board);
            return;
        }
        printf("Your move (e.g., 'd3'): ");
        fgets(player_move, sizeof(player_move), stdin);

        // Validera inmatningen
        if (strlen(player_move) == 3 &&
            player_move[0] >= 'a' && player_move[0] <= 'h' &&
            player_move[1] >= '1' && player_move[1] <= '8')
        {

            input_to_index(player_move, &row, &col);
            if (valid_moves[row][col] == 1)
            {
                make_move(board, row, col, 'B');
                valid_input = 1;
            }
            else
            {
                printf("\nYou already occupy this position! Try again\n ");
            }
        }
        else
        {
            printf("\nNot a valid move, try again.\n");
        }
    }
}

void random_strategy(char board[SIZE][SIZE], char player)
{
    int valid_moves[SIZE][SIZE];
    int possible_moves[SIZE * SIZE][2];
    int move_count = find_valid_moves(board, valid_moves, possible_moves, player);
    print_board(board, valid_moves);
    sleep(1);

    if (move_count == 0)
    {
        printf("No valid moves for %c, skipping turn.\n", player);
        check_game_over(board);
        return;
    }

    int row, col;
    find_random_valid_move(possible_moves, move_count, &row, &col);
    make_move(board, row, col, player);
}

void optimal_strategy(char board[SIZE][SIZE], char player)
{

    printf("not implemented yet.\n");
}
