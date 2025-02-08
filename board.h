#ifndef BOARD_H
#define BOARD_H

#include "config.h"

#define BLACK_PIECE "⚫"
#define WHITE_PIECE "⚪"

void print_board(char board[SIZE][SIZE], int valid_moves[SIZE][SIZE]);

void input_to_index(char input[], int *row, int *col);

int find_valid_moves(char board[SIZE][SIZE], int valid_moves[SIZE][SIZE], int possible_moves[SIZE * SIZE][2], char player);

void find_random_valid_move(int possible_moves[SIZE * SIZE][2], int move_count, int *row, int *col);

void make_move(char board[SIZE][SIZE], int row, int col, char player);

int is_board_full(char board[SIZE][SIZE]);

int has_valid_moves(char board[SIZE][SIZE], char player);

void count_pieces(char board[SIZE][SIZE], int *black_count, int *white_count);

void check_game_over(char board[SIZE][SIZE]);

#endif
