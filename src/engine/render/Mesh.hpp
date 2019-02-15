#pragma once

#include <string>

namespace engine
{
    namespace render
    {
        class Mesh
        {
        public:
            Mesh() = default;
            virtual ~Mesh() = default;
            virtual bool init(const std::string& path) { return false; }
        };
    }
}