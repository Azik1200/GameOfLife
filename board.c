//
// Created by Aziz on 18.06.2022.
//

#include "board.h"
#include <stdlib.h>


board *init_board(int hight, int length){
    board *res = calloc(1, sizeof(board));

    res->length = length;
    res->hight = hight;
    res->buffer1 = calloc(hight*length, sizeof(char));
    res->buffer2 = calloc(hight*length, sizeof(char));

    return res;
}