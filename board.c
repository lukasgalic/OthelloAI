#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
                printf(" * |"); // Valid move position
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

int find_valid_moves(char board[SIZE][SIZE], int valid_moves[SIZE][SIZE], int possible_moves[SIZE * SIZE][2], char player)
{
    char opponent = OPPONENT(player);
    int move_count = 0;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            valid_moves[i][j] = 0;

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (board[row][col] != EMPTY)
                continue;

            int is_valid = 0;
            for (int d = 0; d < 8; d++)
            {
                int r = row + directions[d][0];
                int c = col + directions[d][1];
                int found_opponent = 0;

                while (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == opponent)
                {
                    found_opponent = 1;
                    r += directions[d][0];
                    c += directions[d][1];
                }

                if (found_opponent && r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == player)
                {
                    is_valid = 1;
                    break;
                }
            }

            if (is_valid)
            {
                valid_moves[row][col] = 1;
                possible_moves[move_count][0] = row;
                possible_moves[move_count][1] = col;
                move_count++;
            }
        }
    }
    return move_count;
}

void find_random_valid_move(int possible_moves[SIZE * SIZE][2], int move_count, int *row, int *col)
{
    if (move_count == 0)
    {
        *row = -1;
        *col = -1;
        return;
    }
    srand(time(NULL));
    int random_index = rand() % move_count;
    *row = possible_moves[random_index][0];
    *col = possible_moves[random_index][1];
}

void make_move(char board[SIZE][SIZE], int row, int col, char player)
{
    char opponent = OPPONENT(player);
    board[row][col] = player;

    for (int d = 0; d < 8; d++)
    {
        int r = row + directions[d][0];
        int c = col + directions[d][1];
        int found_opponent = 0;

        while (r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == opponent)
        {
            found_opponent = 1;
            r += directions[d][0];
            c += directions[d][1];
        }

        if (found_opponent && r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == player)
        {
            r = row + directions[d][0];
            c = col + directions[d][1];

            while (board[r][c] == opponent)
            {
                board[r][c] = player;
                r += directions[d][0];
                c += directions[d][1];
            }
        }
    }
}

int is_board_full(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                return 0;
            }
        }
    }
    return 1;
}

int has_valid_moves(char board[SIZE][SIZE], char player)
{
    int valid_moves[SIZE][SIZE];
    int possible_moves[SIZE * SIZE][2];
    return find_valid_moves(board, valid_moves, possible_moves, player) > 0;
}

void count_pieces(char board[SIZE][SIZE], int *black_count, int *white_count)
{
    *black_count = 0;
    *white_count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'B')
            {
                (*black_count)++;
            }
            else if (board[i][j] == 'W')
            {
                (*white_count)++;
            }
        }
    }
}

void check_game_over(char board[SIZE][SIZE])
{
    if (is_board_full(board) || (!has_valid_moves(board, 'B') && !has_valid_moves(board, 'W')))
    {
        int black_count, white_count;
        count_pieces(board, &black_count, &white_count);

        printf("\nGame Over!\n");
        printf("Final Score:\n");
        printf("Black (B): %d\n", black_count);
        printf("White (W): %d\n", white_count);

        if (black_count > white_count)
        {
            printf("Black Wins!\n");
        }
        else if (white_count > black_count)
        {
            printf("White Wins!\n");
        }
        else
        {
            printf("It's a Tie!\n");
        }
        exit(0);
    }
}
