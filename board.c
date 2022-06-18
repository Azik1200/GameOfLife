//
// Created by Aziz on 18.06.2022.
//

#include "board.h"
#include <stdlib.h>


board *init_board(int height, int length){
    board *res = calloc(1, sizeof(board));

    res->length = length;
    res->height = height;
    res->buffer1 = calloc(height * length, sizeof(char));
    res->buffer2 = calloc(height * length, sizeof(char));

    return res;
}

int countNeighbours(board *b, int x, int  y, bool isBuffer1) {
    int res = 0;
    char **curBuf = (char**)(isBuffer1 ? b->buffer1 : b->buffer2);
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue;
            int x_ = (x+i)%b->length;
            int y_ = (y+j)%b->height;
            if(curBuf[y_][x_] == 'O') res++;
        }
    }
    return res;
}