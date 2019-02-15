#include "engine/render/Texture.hpp"
#include "engine/Types.hpp"

namespace engine
{
    namespace render
    {
        class OpenGLTexture : public Texture
        {
        private:
            virtual bool init(const std::string& path) override;
        };
    }
}