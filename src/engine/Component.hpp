#pragma once

#include <memory>

#include "engine/Types.hpp"

namespace engine
{
    class Actor;
    class Component
    {
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