#include <iostream>
#include <stdio.h>

#include "engine/render/opengl_impl/OpenGLRenderer.hpp"
#include "engine/render/opengl_impl/gl_core_3_2.h"

namespace engine
{
    namespace render
    {
        namespace
        {
            const char* getOpenGLLocalizedError(GLenum error)
            {
                const char* result = "Undefined openGL Error";
                switch (error)
                {
                case GL_NO_ERROR:
                    result = "GL_NO_ERROR";
                    break;
                case GL_INVALID_ENUM:
                    result = "GL_INVALID_ENUM";
                    break;
                case GL_INVALID_VALUE:
                    result = "GL_INVALID_VALUE";
                    break;
                case GL_INVALID_OPERATION:
                    result = "GL_INVALID_OPERATION";
                    break;
                case GL_INVALID_FRAMEBUFFER_OPERATION:
                    result = "GL_INVALID_FRAMEBUFFER_OPERATION";
                    break;
                case GL_OUT_OF_MEMORY:
                    result = "GL_OUT_OF_MEMORY";
                    break;
                }
                return result;
            }
        }
        OpenGLRenderer::OpenGLRenderer(U32 width, U32 height)
            : m_width(width)
            , m_height(height)
            , m_validateApiCalls(false)
        {
        }
        
        bool OpenGLRenderer::initialize()
        {
            return ogl_LoadFunctions() == ogl_LOAD_SUCCEEDED;
        }
        
        void OpenGLRenderer::startFrame()
        {
            setViewport(m_viewport);
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            checkGLError(__FUNCTION__);
        }

        void OpenGLRenderer::endFrame()
        {

        }

        void OpenGLRenderer::renderFrame()
        {

        }

        void OpenGLRenderer::setViewport(const math::Rect& viewport)
        {
            m_viewport = viewport;
            glViewport(m_viewport.left.x, m_viewport.left.y, m_viewport.size.x, m_viewport.size.y);
            checkGLError(__FUNCTION__);
        }

        void OpenGLRenderer::clear(ClearMask mask)
        {

        }

        void OpenGLRenderer::setDebugMode(DebugMode mode, bool enabled)
        {
            switch (mode)
            {
            case DebugMode::validateApiCalls:
                m_validateApiCalls = enabled;
                break;
            }
        }

        void OpenGLRenderer::checkGLError(const char* fromFunction)
        {
            if (m_validateApiCalls)
            {
                GLenum err = glGetError();
                if (err != GL_NO_ERROR)
                {
                    auto printError = [](const char* fromFunction, GLenum err) {
                        const U32 buffSize(512);
                        char buff[buffSize];
                        snprintf(buff, buffSize, "[GL ERROR] %s, code %d, %s \n", fromFunction, static_cast<U32>(err), getOpenGLLocalizedError(err));
                        std::cout << buff;
                    };

                    printError(fromFunction, err);
                    while (!(err = glGetError()))
                    {
                        printError(fromFunction, err);
                        std::cout << err;
                    }
                }
            }
        }
        
        // Implement create method
        
        std::shared_ptr<Renderer> Renderer::create(int width, int height)
        {
            std::shared_ptr<Renderer> renderer = std::make_shared<OpenGLRenderer>(width, height);
            
            if(!renderer->initialize())
            {
                return nullptr;
            }
            
            return renderer;
        }
    }
}
