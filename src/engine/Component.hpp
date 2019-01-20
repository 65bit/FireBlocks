#pragma once

#include <memory>

#include "engine/Types.hpp"

namespace engine
{
    class Actor;
    class Component
    {
    public:
        using Id = size_t;
        
    public:
        Component() {}
        virtual ~Component() {}

        virtual bool init() { return true; };
        virtual void deinit() {};

        virtual void update(F32 delta) {};

        U32 getId() const { return m_componentId; }
        void setOwner(std::weak_ptr<Actor> owner) { m_owner = owner; }
    protected:
        U32 m_componentId;
        std::weak_ptr<Actor> m_owner;
    };
}

#define GENERATE_COMPONENT_METADATA(__CLASS__) \
static std::string ComponentName() \
{ \
    return #__CLASS__; \
} \
 \
static Component::Id ComponentId() \
{ \
    std::hash<std::string> hash; \
    return hash(ComponentName()); \
}
