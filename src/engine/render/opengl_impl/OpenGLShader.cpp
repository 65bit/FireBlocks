#include "engine/render/opengl_impl/OpenGLShader.hpp"
#include "engine/render/opengl_impl/gl_core_3_2.h"
#include <fstream>
#include <sstream>

namespace engine
{
    namespace render
    {
        OpenGLShader::OpenGLShader()
            : m_program(0)
        {
        }

        OpenGLShader::~OpenGLShader()
        {
            glDeleteProgram(m_program);
        }

        bool OpenGLShader::init(const std::string& paths)
        {
            return false;
        }

        bool OpenGLShader::init(const std::string& vert, const std::string& frag)
        {
            std::ifstream fragmentFile;
            std::ifstream vertexFile;

            std::stringstream vertexStream;
            std::stringstream fragmentStream;

            std::string vertexProgram;
            std::string fragmentProgram;

            vertexFile.open(vert);
            vertexStream << vertexFile.rdbuf();
            vertexProgram = vertexStream.str();
            vertexFile.close();

            fragmentFile.open(frag);
            fragmentStream << fragmentFile.rdbuf();
            fragmentProgram = fragmentStream.str();
            fragmentFile.close();


            if (fragmentProgram.empty() || vertexProgram.empty())
            {
                return false;
            }

            //vertex
            U32 vertex = glCreateShader(GL_VERTEX_SHADER);
            const char* vertexP = vertexProgram.c_str();
            glShaderSource(vertex, 1, &vertexP, NULL);
            glCompileShader(vertex);
            S32 success;
            glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                return false;
            }
            //fragment
            U32 fragment = glCreateShader(GL_FRAGMENT_SHADER);
            const char* fragmentP = fragmentProgram.c_str();
            glShaderSource(fragment, 1, &fragmentP, NULL);
            glCompileShader(fragment);
            glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                return false;
            }

            //program
            m_program = glCreateProgram();
            glAttachShader(m_program, vertex);
            glAttachShader(m_program, fragment);
            glLinkProgram(m_program);

            glGetProgramiv(m_program, GL_LINK_STATUS, &success);
            if (!success)
            {
                glDeleteProgram(m_program);
                m_program = 0;
                return false;
            }

            glDeleteShader(vertex);
            glDeleteShader(fragment);

            return true;
        }

        void OpenGLShader::use()
        {
            glUseProgram(m_program);
        }
    }
}