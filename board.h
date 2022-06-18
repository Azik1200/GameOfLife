//
// Created by UFAZ on 18.06.2022.
//

#ifndef GAMEOFLIFE_BOARD_H
#define GAMEOFLIFE_BOARD_H

struct board_{
    int hight;
    int length;
    char *buffer1;
    char *buffer2;
};

typedef struct board_ board;

board *init_board(int hight, int length);

#endif //GAMEOFLIFE_BOARD_H
