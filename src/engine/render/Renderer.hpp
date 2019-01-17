#pragma once

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

        class Renderer
        {
            public:
            Renderer() {}
            virtual ~Renderer() {}

            //Frame handling
            virtual void startFrame() = 0;
            virtual void endFrame() = 0;
            virtual void renderFrame() = 0;

            virtual void setViewport() = 0;
            virtual void clear(ClearMask mask) = 0;

            //Debug handling
            virtual void setDebugMode() = 0;
        };
    }
}