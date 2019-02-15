#pragma once

#include <string>

namespace engine
{
    namespace render
    {
        class Texture
        {
        public:
            Texture() = default;
            virtual ~Texture() = default;
            virtual bool init(const std::string& path) { return false; }
        };
    }
}