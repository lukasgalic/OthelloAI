#ifndef BOARD_H
#define BOARD_H

#include "config.h"

#define BLACK_PIECE "⚫"
#define WHITE_PIECE "⚪"

void print_board(char board[SIZE][SIZE], int valid_moves[SIZE][SIZE]);

void input_to_index(char input[], int *row, int *col);

void find_valid_moves(char board[8][8], int valid_moves[8][8], char player);

#endif
