//
// Created by UFAZ on 18.06.2022.
//

#ifndef GAMEOFLIFE_BOARD_H
#define GAMEOFLIFE_BOARD_H

#include "stdbool.h"

struct board_{
    int height;
    int length;
    char *buffer1;
    char *buffer2;
};

typedef struct board_ board;

board *init_board(int height, int length);

int countNeighbors(board *b, int x, int  y, bool isBuffer1);



#endif //GAMEOFLIFE_BOARD_H
