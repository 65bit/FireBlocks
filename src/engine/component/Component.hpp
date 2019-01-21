#pragma once

#include <memory>
#include <string>

#include "engine/Types.hpp"

namespace engine
{
	namespace gameplay
	{
		class Actor;
	}

	namespace component
	{
		class Component
		{
		public:
			using Id = size_t;

		public:
			Component(std::weak_ptr<gameplay::Actor> owner);
			virtual ~Component() = default;

			virtual bool init() { return true; }
			virtual void deinit() {};
			virtual void update(F32 delta) {};

			virtual Id componentId() const = 0;
			virtual std::string componentName() const = 0;

		protected:
			std::weak_ptr<gameplay::Actor> m_owner;
		};
	}
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
