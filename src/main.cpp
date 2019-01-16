#include "SDL2/SDL.h"
#include "SDL2_net/SDL_net.h"

#include <iostream>

int main(int _argc, char** _argv)
{
    SDL_Init(SDL_INIT_VIDEO);   // Initialize SDL2
    
    SDL_Window *window;        // Declare a pointer to an SDL_Window
    
    // Create an application window with the following settings:
    window = SDL_CreateWindow(
                              "An SDL2 window",         //    const char* title
                              SDL_WINDOWPOS_UNDEFINED,  //    int x: initial x position
                              SDL_WINDOWPOS_UNDEFINED,  //    int y: initial y position
                              640,                      //    int w: width, in pixels
                              480,                      //    int h: height, in pixels
                              SDL_WINDOW_SHOWN          //    Uint32 flags: window options, see docs
                              );
    
    // Check that the window was successfully made
    if(window==NULL){
        // In the event that the window could not be made...
        std::cout << "Could not create window: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }
    
    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }
    }
    
    // Close and destroy the window
    SDL_DestroyWindow(window);
    
    // Clean up SDL2 and exit the program
    SDL_Quit();
    return 0;
}
