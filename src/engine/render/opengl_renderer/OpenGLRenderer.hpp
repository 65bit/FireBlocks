#pragma once

#include "engine/render/Renderer.hpp"

namespace engine
{
    namespace render
    {
        class OpenglRenderer : public Renderer
        {
        public:
            OpenglRenderer(int width, int height, void* context);
            virtual ~OpenglRenderer() {}

            //Frame handling
            virtual void startFrame() override;
            virtual void endFrame() override;
            virtual void renderFrame() override;

            virtual void setViewport() override;
            virtual void clear(ClearMask mask) override;

            //Debug handling
            virtual void setDebugMode() override;

        private:
            void* m_context;
			int m_width;
			int m_height;
        };
    }
}