#pragma once

#include <string>

namespace engine
{
    namespace render
    {
        class Shader
        {
        public:
            Shader() = default;
            virtual ~Shader() = default;
            virtual bool init(const std::string& paths) { return false; }
            virtual bool init(const std::string& vert, const std::string& frag) { return false; }

            virtual void use() {};
        };
    }
}