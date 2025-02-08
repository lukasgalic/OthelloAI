#ifndef STRATEGY_H
#define STRATEGY_H

#include "config.h"

void human_strategy(char board[SIZE][SIZE], char player);

void random_strategy(char board[SIZE][SIZE], char player);

void optimal_strategy(char board[SIZE][SIZE], char player);

#endif
