#pragma once

#include <memory>

namespace engine
{
    namespace render
    {
        class Window
        {
        public:
            virtual ~Window() = default;
            
            virtual bool initialize() = 0;
            
            // Swaps back buffer with front buffer
            virtual void present() = 0;
            
            // Implement in impl module
            static std::shared_ptr<Window> create(int width, int height);
        };
    }
}
