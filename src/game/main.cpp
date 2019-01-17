#if defined(FB_OSX)
#include "SDL2/SDL.h"
#include "SDL2_net/SDL_net.h"
#elif defined(FB_WIN)
#include "SDL.h"
#include "SDL_net.h"
#else
#error "Unsupported platform"
#endif

#include <iostream>
#include <memory>

#include "engine/render/scene_renderer/SceneRenderer.hpp"

int main(int _argc, char** _argv)
{
    SDL_Init(SDL_INIT_VIDEO);   // Initialize SDL2
    
    SDL_Window *window;        // Declare a pointer to an SDL_Window
    
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Create an application window with the following settings:
	const int width = 640;
	const int height = 480;
    window = SDL_CreateWindow(
                              "An SDL2 window",         //    const char* title
                              SDL_WINDOWPOS_UNDEFINED,  //    int x: initial x position
                              SDL_WINDOWPOS_UNDEFINED,  //    int y: initial y position
                              width,                      //    int w: width, in pixels
                              height,                      //    int h: height, in pixels
                              SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN          //    Uint32 flags: window options, see docs
                              );
    
    // Check that the window was successfully made
    if(window==NULL){
        // In the event that the window could not be made...
        std::cout << "Could not create window: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }
    
	auto openglContext = SDL_GL_CreateContext(window);

	SDL_GL_MakeCurrent(window, openglContext);
	std::unique_ptr<engine::SceneRender> sceneRenderer(new engine::SceneRender(width, height, openglContext));

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
        
		sceneRenderer->startFrame();
		sceneRenderer->renerFrame();
		sceneRenderer->endFrame();
		SDL_GL_SwapWindow(window);
    }
    
    // Close and destroy the window
    SDL_DestroyWindow(window);
    
    // Clean up SDL2 and exit the program
    SDL_Quit();
    return 0;
}
