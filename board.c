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