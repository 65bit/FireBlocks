#pragma once

namespace engine
{
    namespace gameplay
    {
        class GameModule
        {
        public:
            virtual ~GameModule() = default;
      
            virtual void onBeforeUpdate() {};
            virtual void onAfterUpdate() {};
            
            virtual void onBeforeRender() {};
            virtual void onAfterRender() {};
            
            virtual void onApplicationInitialized() {};
        };
    }
}
