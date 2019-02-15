#include "engine/render/Shader.hpp"
#include "engine/Types.hpp"

namespace engine
{
    namespace render
    {
        class OpenGLShader : public Shader
        {
        private:
            OpenGLShader();
            ~OpenGLShader();

            virtual bool init(const std::string& paths) override;
            bool init(const std::string& vert, const std::string& frag) override;

            virtual void use() override;

            U32 m_program;
        };
    }
}