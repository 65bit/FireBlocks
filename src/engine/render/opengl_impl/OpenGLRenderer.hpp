#pragma once

#include "engine/render/Renderer.hpp"

namespace engine
{
    namespace render
    {
        class OpenGLRenderer : public Renderer
        {
        public:
            OpenGLRenderer(int width, int height);
        
        private:
            virtual bool initialize() override;
            
            //Frame handling
            virtual void startFrame() override;
            virtual void endFrame() override;
            virtual void renderFrame() override;

            virtual void setViewport() override;
            virtual void clear(ClearMask mask) override;

            //Debug handling
            virtual void setDebugMode() override;
            
        private:
            const int m_width;
            const int m_height;
        };
    }
}
