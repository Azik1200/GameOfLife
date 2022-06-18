#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char **argv){
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

    // here should be game logic


        RendererCreationError:
   SDL_DestroyWindow( window );
   SDL_QuitSubSystem( flags );
        WindowCreationError:
    SDL_Quit();
    SDLInitializationError:
    return 0;
}
