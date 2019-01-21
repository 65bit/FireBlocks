#pragma once

#include <memory>

#include "engine/math/Rect.hpp"

namespace engine
{
    namespace render
    {
        enum class ClearMask
        {
            None,
            Color,
            Depth,
            Stencil,
            All
        };

        enum class DebugMode
        {
            validateApiCalls
        };

        class Renderer
        {
        public:
            virtual ~Renderer() = default;

            virtual bool initialize() = 0;
            
            //Frame handling
            virtual void startFrame() = 0;
            virtual void endFrame() = 0;
            virtual void renderFrame() = 0;

            virtual void setViewport(const math::Rect& viewport) = 0;
            virtual void clear(ClearMask mask) = 0;

            //Debug handling
            virtual void setDebugMode(DebugMode mode, bool enabled) = 0;
            
            // Implement in impl module
            static std::shared_ptr<Renderer> create(int  width, int height);
        };
    }
}
