#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <time.h>
#include "board.h"

bool quit = false;
int square_size = 5;

void draw_board(board *b, int cam_x, int cam_y, SDL_Renderer *renderer){

    SDL_Rect rect;
    rect.w = square_size; rect.h = square_size;
    char *currBuf = (b->isBuffer1 ? b->buffer1 : b->buffer2);

    int screenHeight, screenWidth;
    SDL_GetRendererOutputSize( renderer, &screenWidth, &screenHeight );

    for(int y = 0; y < b->height; y++){
        for(int x = 0; x < b->length; x++){
            int y_ = y * square_size - cam_y;
            int x_ = x * square_size - cam_x;
            // draw only pixels that can be displayed on a screen;
            if((x_ > -2*square_size && y > -2*square_size) &&
            (x_ < screenWidth + 2*square_size && y_ < screenHeight + 2*square_size)){
                rect.x = x_;
                rect.y = y_;
                if(currBuf[y * b->length + x] == 1){
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                } else {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                }
                SDL_RenderDrawRect(renderer, &rect);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
    SDL_RenderPresent(renderer);
}

int main(int argc, char **argv){
    srand(time(NULL));
    printf("Life is a game!\n");

    // Setup SDL
    if(SDL_Init(SDL_INIT_VIDEO) == -1){
        fprintf(stderr, "Error while initializing SDL: %s\n", SDL_GetError( ) );
        goto SDLInitializationError;
    }

    // Create a window
    SDL_WindowFlags flags =
            SDL_WINDOW_SHOWN | SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_MINIMIZED;
    SDL_Window *window = SDL_CreateWindow(
            "Conway's game of life",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            1280,
            720,
            flags );
    if(window == NULL){
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError( ) );
        goto WindowCreationError;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL){
        fprintf(stderr, "error creating renderer: %s\n", SDL_GetError());
        goto RendererCreationError;
    }

    board *b = init_board(1000, 1000);
    seed_board(b, 400*400);
    SDL_Event e;

    while (!quit){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT)
                quit = true;
        }
        draw_board(b, 0, 0, renderer);
    }

    RendererCreationError:
    SDL_DestroyWindow( window );
    SDL_QuitSubSystem( flags );
    WindowCreationError:
    SDL_Quit();
    SDLInitializationError:
    return 0;
}