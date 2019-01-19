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
            OpenGLWindow(int width, int height);
            virtual ~OpenGLWindow() throw() override;
            
        private:
            virtual bool initialize() override;
            virtual void present() override;
            
        private:
            bool m_initialized;
            
            const int m_width;
            const int m_height;
            
            SDL_Window* m_window;
            SDL_GLContext m_context;
        };
    }
}
