#pragma once

#include <memory>

#include "engine/render/Renderer.hpp"
#include "engine/gameplay/Scene.hpp"

namespace engine
{
    namespace render
    {
        class SceneRender final
        {
        public:
            SceneRender(int width, int height);
            ~SceneRender();

            void setScene(std::shared_ptr<gameplay::Scene> scene);
            std::shared_ptr<gameplay::Scene> getScene() const { return m_scene; }

            void startFrame();
            void renerFrame();
            void endFrame();

        private:
            std::shared_ptr<render::Renderer> m_renderer;
            std::shared_ptr<gameplay::Scene> m_scene;
        };
    }
}
