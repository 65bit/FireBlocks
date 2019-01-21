#include "engine/component/Component.hpp"

namespace engine
{
	namespace component
	{
		Component::Component(std::weak_ptr<gameplay::Actor> owner)
			: m_owner(owner)
		{
			
		}
	}
}