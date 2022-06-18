//
// Created by UFAZ on 18.06.2022.
//

#ifndef GAMEOFLIFE_BOARD_H
#define GAMEOFLIFE_BOARD_H

#include "stdbool.h"

//! Here we define struct board_. It use double buffering.
struct board_ {
    int height;
    int length;
    char *buffer1;
    char *buffer2;
    bool isBuffer1;
};

//! Defining typedef for struct board_.
typedef struct board_ board;

//! Init for the board. Accept height and length.
board *init_board(int height, int length);

//! Count Neighbors of point, where x is line and y is colum.
int countNeighbours(board *b, int x, int y);

//! Function that changes state of the board
void evolve_board(board *b);

//! Function that fills board with living cells
void seed_board(board *b, int population);

//! Function that clears memory taken by board
void free_board(board *b);
#endif //GAMEOFLIFE_BOARD_H
