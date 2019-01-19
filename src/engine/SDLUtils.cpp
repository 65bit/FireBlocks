#include <iostream>

#include "engine/SDLUtils.hpp"

namespace sdl_utils
{
    void LogSDLError(const std::string& _message)
    {
        std::cout << "[ERROR]: " << _message << " [REASON]: " << SDL_GetError() << std::endl;
    }
}

