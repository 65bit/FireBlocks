#pragma once

#include <map>
#include <memory>
#include <vector>

#include "engine/Component.hpp"
#include "engine/Types.hpp"

namespace engine {

class Actor{
public:
    using Components = std::map<Component::Id, std::shared_ptr<Component>>;
    using Childs = std::vector<std::shared_ptr<Actor>>;
public:
    virtual ~Actor() = default;

    virtual bool init() { return true; }
    virtual void deinit() {}

    virtual void update(F32 delta) {
        for (auto& it : m_components) {
            auto& component = it.second;
            component->update(delta);
        }

        for (auto& actor : m_children) {
            actor->update(delta);
        }
    }

    void addChild(std::shared_ptr<Actor> actor) {
        auto foundIt = std::find(m_children.begin(), m_children.end(), actor);

        if (foundIt == m_children.end()) {
            m_children.push_back(actor);
        }
    }

    void removeChild(std::shared_ptr<Actor> actor) {
        auto foundIt = std::find(m_children.begin(), m_children.end(), actor);

        if (foundIt != m_children.end()) {
            m_children.erase(foundIt);
        }
    }

    const Childs& getChilds() const { return m_children; }

    template<typename T, typename... Args>
    void addComponent(Args&&... args)
    {
        const auto id = T::ComponentIdStatic();
        
        if(m_components.count(id))
        {
            return;
        }
        
        m_components[id] = std::make_shared<T>(std::forward<Args>(args)...);
    }
    
    template<typename T>
    std::shared_ptr<T> getComponent()
    {
        const auto id = T::ComponentIdStatic();
        
        if(!m_components.count(id))
        {
            return nullptr;
        }
        
        auto component = m_components.at(id);
        
        if(component->componentId() != id)
        {
            return nullptr;
        }
        
        return std::static_pointer_cast<T>(component);
    }
    
private:
    Components m_components;
    Childs m_children;
};
}
