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

        void SceneRender::setScene(std::shared_ptr<Scene> scene)
        {
            m_scene = scene;
        }

        void SceneRender::startFrame()
        {
            m_renderer->startFrame();
        }

        void SceneRender::renerFrame()
        {
            if (!m_scene)
            {
                return;
            }
            auto root = m_scene->getRoot();
            if (!root)
            {
                return;
            }
            
            //TODO: get root, gather all meshes with positions and materials
        }

        void SceneRender::endFrame()
        {
            m_renderer->endFrame();
        }
    }
}
