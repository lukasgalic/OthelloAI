#include <stdio.h>
#include "board.h"

#define EMPTY '.'
#define OPPONENT(player) (player == 'W' ? 'B' : 'W')

const int directions[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void print_board(char board[SIZE][SIZE], int valid_moves[SIZE][SIZE])
{
    printf("\n    a   b   c   d   e   f   g   h  \n");
    printf("   +---+---+---+---+---+---+---+---+\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf(" %d |", i + 1); // Row numbering

        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'B')
            {
                printf("%s |", BLACK_PIECE);
            }
            else if (board[i][j] == 'W')
            {
                printf("%s |", WHITE_PIECE);
            }
            else if (valid_moves[i][j] == 1)
            {
                printf(" * |"); // Valid move
            }
            else
            {
                printf("   |");
            }
        }
        printf("\n");

        if (i < SIZE - 1)
        {
            printf("   +---+---+---+---+---+---+---+---+\n");
        }
    }

    printf("   +---+---+---+---+---+---+---+---+\n");
}

void input_to_index(char input[], int *row, int *col)
{
    *col = input[0] - 'a';
    *row = (input[1] - '0') - 1;
}

void find_valid_moves(char board[SIZE][SIZE], int valid_moves[SIZE][SIZE], char player)
{
    char opponent = OPPONENT(player);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            valid_moves[i][j] = 0;
        }
    }

    // Check each empty cell
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (board[row][col] != EMPTY)
                continue; // Skip occupied cells

            // Check all 8 directions
            int is_valid = 0;
            for (int d = 0; d < 8; d++)
            {
                int r = row + directions[d][0];
                int c = col + directions[d][1];
                int found_opponent = 0;

                // Move in one direction
                while (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == opponent)
                {
                    found_opponent = 1;
                    r += directions[d][0];
                    c += directions[d][1];
                }

                // If found an opponent and reached a player's piece, it's a valid move
                if (found_opponent && r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == player)
                {
                    is_valid = 1;
                    break; // No need to check more directions
                }
            }

            // Mark the move as valid if at least one direction is valid
            if (is_valid)
            {
                valid_moves[row][col] = 1;
            }
        }
    }
}
