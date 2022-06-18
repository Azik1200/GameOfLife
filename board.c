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
    res->isBuffer1 = true;

    return res;
}

int countNeighbours(board *b, int x, int y) {
    int res = 0;
    char **curBuf = (char**)(b->isBuffer1 ? b->buffer1 : b->buffer2);
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue;
            int x_ = (x+j)%b->length;
            int y_ = (y+i)%b->height;
            if(curBuf[y_][x_] == 1) res++;
        }
    }
    return res;
}

void evolve_board(board *b){
    char **currBuf = (char **)(b->isBuffer1 ? b->buffer1 : b->buffer2);
    char **nextBuf = (char **)(b->isBuffer1 ? b->buffer2 : b->buffer1);

    for(int i = 0; i < b->height; i++){
        for(int j = 0; j < b->length; j++){
            int n = countNeighbours(b, j, i);
            if(currBuf[i][j] == 1 && (n == 2 || n == 3)) nextBuf[i][j] = 1;
            else if(currBuf[i][j] == 0 && (n == 3)) nextBuf[i][j] = 1;
            else nextBuf[i][j] = 0;
        }
    }
    b->isBuffer1 = b->isBuffer1 ? false : true;

}