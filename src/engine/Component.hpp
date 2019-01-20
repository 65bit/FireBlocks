#pragma once

#include <memory>
#include <string>

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

        virtual Id componentId() const = 0;
        virtual std::string componentName() const = 0;
        
        void setOwner(std::weak_ptr<Actor> owner) { m_owner = owner; }
    protected:
        std::weak_ptr<Actor> m_owner;
    };
}

#define GENERATE_COMPONENT_METADATA(__CLASS__) \
static std::string ComponentNameStatic() \
{ \
    return #__CLASS__; \
} \
static Component::Id ComponentIdStatic() \
{ \
    std::hash<std::string> hash; \
    return hash(ComponentNameStatic()); \
} \
virtual Component::Id componentId() const override \
{ \
    return __CLASS__::ComponentIdStatic(); \
} \
virtual std::string componentName() const override \
{ \
    return __CLASS__::ComponentNameStatic(); \
}
