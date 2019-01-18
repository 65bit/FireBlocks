#pragma once

#include "engine/render/Renderer.hpp"
#include <memory>

namespace engine
{
    class SceneRender final
    {
    public:
        SceneRender(int width, int height, void* context);
        ~SceneRender();

        void startFrame();
        void renerFrame();
        void endFrame();

    private:
        void* m_context;
        std::unique_ptr<render::Renderer> m_renderer;
    };
}
