#pragma once

#include <memory>

#include "engine/render/Renderer.hpp"
#include "engine/scene_graph/Scene.hpp"

namespace engine
{
    namespace render
    {
        class SceneRender final
        {
        public:
            SceneRender(int width, int height);
            ~SceneRender();

            void setScene(std::shared_ptr<Scene> scene);
            std::shared_ptr<Scene> getScene() const { return m_scene; }

            void startFrame();
            void renerFrame();
            void endFrame();

        private:
            std::shared_ptr<render::Renderer> m_renderer;
            std::shared_ptr<Scene> m_scene;
        };
    }
}
