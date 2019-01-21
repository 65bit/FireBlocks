#pragma once

#include "engine/Types.hpp"
#include <glm/vec2.hpp>
#include <glm/gtc/type_precision.hpp>

namespace engine
{
    namespace math
    {
        struct Rect
        {
            glm::i32vec2 left;
            glm::i32vec2 size;
        };
    }
}