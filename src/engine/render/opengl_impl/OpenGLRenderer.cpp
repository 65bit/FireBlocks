#include "engine/render/opengl_impl/OpenGLRenderer.hpp"
#include "engine/render/opengl_impl/gl_core_3_2.h"

namespace engine
{
    namespace render
    {
        OpenGLRenderer::OpenGLRenderer(int width, int height)
            : m_width(width)
            , m_height(height)
        {
            
        }
        
        bool OpenGLRenderer::initialize()
        {
            return ogl_LoadFunctions() == ogl_LOAD_SUCCEEDED;
        }
        
        void OpenGLRenderer::startFrame()
        {
            glViewport(0, 0, m_width, m_height); // TODO! these should be set from viewport
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void OpenGLRenderer::endFrame()
        {

        }

        void OpenGLRenderer::renderFrame()
        {

        }

        void OpenGLRenderer::setViewport()
        {

        }

        void OpenGLRenderer::clear(ClearMask mask)
        {

        }

        void OpenGLRenderer::setDebugMode()
        {

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
