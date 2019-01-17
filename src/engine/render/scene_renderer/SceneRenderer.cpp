#include "SceneRenderer.hpp"
#include "engine\render\opengl_renderer\OpenGLRenderer.hpp"

namespace engine
{

    SceneRender::SceneRender(int width, int height, void* context)
    {
        m_renderer.reset(new render::OpenglRenderer(width, height, context));
    }

    SceneRender::~SceneRender()
    {

    }

    void SceneRender::startFrame()
    {
        m_renderer->startFrame();
    }

    void SceneRender::renerFrame()
    {

    }

    void SceneRender::endFrame()
    {
        m_renderer->endFrame();
    }

}