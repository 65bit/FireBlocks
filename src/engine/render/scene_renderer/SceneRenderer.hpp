#pragma once

#include "engine/render/Renderer.hpp"
#include <memory>

namespace engine
{
    namespace render
    {
        class SceneRender final
        {
        public:
            SceneRender(int width, int height);
            ~SceneRender();

            void startFrame();
            void renerFrame();
            void endFrame();

        private:
            std::shared_ptr<render::Renderer> m_renderer;
        };
    }
}
