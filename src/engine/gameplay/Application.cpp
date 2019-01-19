#include "engine/gameplay/Applicaion.hpp"
#include "engine/render/Window.hpp"
#include "engine/SDLUtils.hpp"

namespace engine
{
    namespace gameplay
    {
        void Application::run()
        {
            if(!init())
            {
                return;
            }
            
            const int screenWidth = 640;
            const int screenHeight = 480;
            
            m_window = render::Window::create(screenWidth, screenHeight);
            m_sceneRenderer = std::make_shared<render::SceneRender>(screenWidth, screenHeight);
            
            bool appClosed = false;
            
            while(!appClosed)
            {
                SDL_Event event;
                
                while(SDL_PollEvent(&event))
                {
                    appClosed = event.type == SDL_QUIT;
                }
                
                if(!appClosed)
                {
                    m_sceneRenderer->startFrame();
                    m_sceneRenderer->renerFrame();
                    m_sceneRenderer->endFrame();
                    
                    m_window->present();
                }
            }
            
            deinit();
        }
        
        bool Application::init()
        {
            if(SDL_Init(SDL_INIT_EVERYTHING))
            {
                sdl_utils::LogSDLError("Unnable to initialize SDL");
                return false;
            }
            
            return true;
        }
        
        void Application::deinit()
        {
            SDL_Quit();
        }
    }
}
