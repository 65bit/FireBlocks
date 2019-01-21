#pragma once

#include "engine/render/Renderer.hpp"
#include "engine/Types.hpp"

namespace engine
{
    namespace render
    {
        class OpenGLRenderer : public Renderer
        {
        public:
            OpenGLRenderer(U32 width, U32 height);

        private:
            virtual bool initialize() override;
            
            //Frame handling
            virtual void startFrame() override;
            virtual void endFrame() override;
            virtual void renderFrame() override;

            virtual void setViewport(const math::Rect& viewport) override;
            virtual void clear(ClearMask mask) override;

            //Debug handling
            virtual void setDebugMode(DebugMode mode, bool enabled) override;
            void checkGLError(const char* fromFunction);

        private:
            U32 m_width;
            U32 m_height;
            math::Rect m_viewport;
            bool m_validateApiCalls;
        };
    }
}
