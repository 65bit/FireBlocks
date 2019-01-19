#pragma once

#include <map>
#include <memory>
#include <vector>

#include "engine/Component.hpp"
#include "engine/Types.hpp"

namespace engine {

class Actor{
public:
    using Components = std::map<U64, std::shared_ptr<Component>>;
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

    template <class ComponetClass> // TODO: getComponent without ID
    std::shared_ptr<ComponetClass> getComponent(U32 id) {
        const auto foundIt = m_components.find(id);
        if (foundIt != m_components.end()) {
            std::shared_ptr<Component> base(foundIt->second);
            std::shared_ptr<ComponetClass> component(std::static_pointer_cast<ComponetClass>(base));
            return component;
        }
        else {
            return std::shared_ptr<ComponetClass>();
        }
    }

    void addComponent(std::shared_ptr<Component> component) { m_components[component->getId()] = component; }

private:
    Components m_components;
    Childs m_children;
};
}
