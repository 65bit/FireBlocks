#pragma once

#include "engine/render/Window.hpp"
#include "engine/SDLUtils.hpp"

namespace engine
{
    namespace render
    {
        class OpenGLWindow
        : public Window
        {
            using Parent = Window;

        public:
            OpenGLWindow(U32 width, U32 height);
            virtual ~OpenGLWindow() override;

        private:
            virtual bool initialize() override;
            virtual void present() override;

            virtual U32 getWidth() const override;
            virtual U32 getHeight() const override;

        private:
            bool m_initialized;
            
            const U32 m_width;
            const U32 m_height;
            
            SDL_Window* m_window;
            SDL_GLContext m_context;
        };
    }
}
