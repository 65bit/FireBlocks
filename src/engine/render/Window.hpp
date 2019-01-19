#pragma once

#include <memory>

#include "engine/Types.hpp"

namespace engine
{
    namespace render
    {
        class Window
        {
        public:
            // Implement in impl module
            static std::shared_ptr<Window> create(U32 width, U32 height);

        public:
            virtual ~Window() = default;

            virtual bool initialize() = 0;

            virtual U32 getWidth() const = 0;
            virtual U32 getHeight() const = 0;

            // Swaps back buffer with front buffer
            virtual void present() = 0;
        };
    }
}
