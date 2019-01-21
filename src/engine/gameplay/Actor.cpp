#include "engine/gameplay/Actor.hpp"

namespace engine
{
	namespace gameplay
	{
		void Actor::update(F32 delta)
		{
			for (auto& it : m_components) 
			{
				it.second->update(delta);
			}

			for (auto& actor : m_children) 
			{
				actor->update(delta);
			}
		}

		void Actor::addChild(std::shared_ptr<Actor> actor)
		{
			auto foundIt = std::find(m_children.begin(), m_children.end(), actor);

			if (foundIt == m_children.end()) 
			{
				m_children.push_back(actor);
			}
		}

		void Actor::removeChild(std::shared_ptr<Actor> actor) 
		{
			auto foundIt = std::find(m_children.begin(), m_children.end(), actor);

			if (foundIt != m_children.end()) 
			{
				m_children.erase(foundIt);
			}
		}

		const Actor::Childs& Actor::getChilds() const
		{ 
			return m_children; 
		}
	}
}