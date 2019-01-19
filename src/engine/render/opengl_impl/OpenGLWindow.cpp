#include "engine/render/opengl_impl/OpenGLWindow.hpp"

namespace engine
{
    namespace render
    {
        OpenGLWindow::OpenGLWindow(U32 width, U32 height)
        : m_initialized(false)
        , m_width(width)
        , m_height(height)
        , m_window(nullptr)
        , m_context(nullptr)
        {
            
        }
        
        OpenGLWindow::~OpenGLWindow() throw()
        {
            if(m_context)
            {
                SDL_GL_DeleteContext(m_context);
                m_context = nullptr;
            }
            
            if(m_window)
            {
                SDL_DestroyWindow(m_window);
                m_window = nullptr;
            }
            
            m_initialized = false;
        }
        
        bool OpenGLWindow::initialize()
        {
            SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
            SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            
            auto window = SDL_CreateWindow("Engine"
                                           , SDL_WINDOWPOS_UNDEFINED
                                           , SDL_WINDOWPOS_UNDEFINED
                                           , m_width
                                           , m_height
                                           , SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
            
            if(!window)
            {
                sdl_utils::LogSDLError("Unnable to create window");
                return false;
            }
            
            auto context = SDL_GL_CreateContext(window);
            
            if(!context)
            {
                SDL_DestroyWindow(window);
                sdl_utils::LogSDLError("Unnable to create GL context");
                
                return false;
            }
            
            if(SDL_GL_MakeCurrent(window, context))
            {
                SDL_GL_DeleteContext(context);
                SDL_DestroyWindow(window);
                
                sdl_utils::LogSDLError("Unnable to setup GL context");
                
                return false;
            }
            
            m_window = window;
            m_context = context;
            m_initialized = true;
            
            return true;
        }

        std::shared_ptr<Window> Window::create(U32 width, U32 height)
        {
            std::shared_ptr<Window> window = std::make_shared<OpenGLWindow>(width, height);
            
            if(!window->initialize())
            {
                return nullptr;
            }
            
            return window;
        }

        void OpenGLWindow::present()
        {
            if(!m_initialized)
            {
                return;
            }
            
            SDL_GL_SwapWindow(m_window);
        }

        U32 OpenGLWindow::getWidth() const
        {
            return m_width;
        }

        U32 OpenGLWindow::getHeight() const
        {
            return m_height;
        }
    }
}
