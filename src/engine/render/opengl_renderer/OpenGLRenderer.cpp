#include "OpenGLRenderer.hpp"
#ifdef _WIN32
#include "gl_core_4_4_mac.h"
#else
#include "gl_core_4_4.h"
#endif

namespace engine
{
    namespace render
    {

        OpenglRenderer::OpenglRenderer(int width, int height, void* context)
            : m_width(width)
            , m_height(height)
        {
            ogl_LoadFunctions();
        }

        void OpenglRenderer::startFrame()
        {
            glViewport(0, 0, m_width, m_height); // TODO! these should be set from viewport
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void OpenglRenderer::endFrame()
        {

        }

        void OpenglRenderer::renderFrame()
        {

        }

        void OpenglRenderer::setViewport()
        {

        }

        void OpenglRenderer::clear(ClearMask mask)
        {

        }

        void OpenglRenderer::setDebugMode()
        {

        }
    }
}