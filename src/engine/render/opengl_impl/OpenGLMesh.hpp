#include "engine/render/Mesh.hpp"
#include "engine/Types.hpp"

namespace engine
{
    namespace render
    {
        class OpenGLMesh : public Mesh
        {
        private:
            virtual bool init(const std::string& path) override;
        };
    }
}