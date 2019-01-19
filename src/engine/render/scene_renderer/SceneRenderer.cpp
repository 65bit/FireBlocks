#include "engine/render/scene_renderer/SceneRenderer.hpp"
#include "engine/render/Renderer.hpp"

namespace engine
{
    namespace render
    {
        SceneRender::SceneRender(int width, int height)
        {
            m_renderer = Renderer::create(width, height);
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
}
