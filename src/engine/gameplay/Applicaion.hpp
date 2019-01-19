#pragma once

#include "engine/render/scene_renderer/SceneRenderer.hpp"
#include "engine/render/Window.hpp"

namespace engine
{
    namespace gameplay
    {
        class Application
        {
        public:
            void run();

        private:
            bool init();
            void deinit();
            
        private:
            std::shared_ptr<render::SceneRender> m_sceneRenderer;
            std::shared_ptr<render::Window> m_window;
        };
    }
}
