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
    char *curBuf = (b->isBuffer1 ? b->buffer1 : b->buffer2);
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue;
            int x_ = ((x+j)%b->length + b->length) % b->length;
            int y_ = ((y+i)%b->height + b->height) % b->height;
            if(curBuf[y_ * b->length + x_] == 1) res++;
        }
    }
    return res;
}

void evolve_board(board *b){
    char *currBuf = (b->isBuffer1 ? b->buffer1 : b->buffer2);
    char *nextBuf = (b->isBuffer1 ? b->buffer2 : b->buffer1);

    for(int i = 0; i < b->height; i++){
        for(int j = 0; j < b->length; j++){
            int n = countNeighbours(b, j, i);
            if(currBuf[i * b->length + j] == 1 && (n == 2 || n == 3)) nextBuf[i * b->length + j] = 1;
            else if(currBuf[i * b->length + j] == 0 && (n == 3)) nextBuf[i * b->length + j] = 1;
            else nextBuf[i * b->length + j] = 0;
        }
    }
    b->isBuffer1 = b->isBuffer1 ? false : true;
}
void seed_board(board *b, int population){
    population = population > 0 ? population : -population;
    int pop = b->length*b->height < population ? b->length * b->height : population;
    double density = (double) pop / (double )(b->height * b->length);
    char *currBuf = (char *)(b->isBuffer1 ? b->buffer1 : b->buffer2);
    for(int i = 0; i < b->length * b->height; i++){
        double chance = (double)rand() / (double)RAND_MAX;
        if(chance < density) currBuf[i] = 1;
        else currBuf[i] = 0;
    }
}

void free_board(board *b){
    free(b->buffer1);
    free(b->buffer2);
    free(b);
}