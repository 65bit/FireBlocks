#pragma once

#include <string>

#if defined(FB_OSX)
    #include <SDL2/SDL.h>
#elif defined(FB_WIN)
    #include <SDL.h>
#endif

namespace sdl_utils
{
    extern void LogSDLError(const std::string& _message);
}
